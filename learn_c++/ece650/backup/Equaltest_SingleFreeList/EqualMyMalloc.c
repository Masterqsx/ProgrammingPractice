#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<sys/time.h>
#include<stdint.h>


#define NUM_ITERS    10000
#define NUM_ITEMS    10000
#define ALLOC_SIZE   128



#define WSIZE 4
#define DSIZE 8
#define MINSIZE 16
#define CHUNKSIZE (1<<7)
#define PADDING(size) (((size+4)/16+1)*16)

#define MALLOC(sz) m_malloc_first(sz)
#define FREE(p)    m_free_noncoalesce(p)

#define MAX(x,y) (((x)>(y))? (x):(y))
#define GET(addr) (*(size_t *)(addr))
#define PUT(addr, value) (*((size_t *)(addr))=(size_t)(value))
#define GET_SIZE(addr) (GET(addr) & (~0x7))
#define GET_ALLOC(addr) (GET(addr) & 0x1)
#define PACK(size,alloc) ((size)|(alloc))

#define HA(addr) ((char *)(addr)-WSIZE) //get head block address
#define FA(addr) ((char *)(addr)+GET_SIZE(HA(addr))-DSIZE)//get foot block address
#define FLN(addr) ((char *)(addr))
#define FLP(addr) ((char *)(addr)+WSIZE)

#define PRE_BLOCK(addr) (addr-GET_SIZE(addr-DSIZE))
#define NEXT_BLOCK(addr) (FA(addr)+DSIZE)
#define NFA(addr) GET(FLN(addr))
#define PFA(addr) GET(FLP(addr))
#define FFA GET(list_start)
#define EFA GET(FLP(list_end))

char *heap_start=NULL;
char *list_start=NULL;
char *list_end=NULL;
char *heap_end=NULL;
int heap_size=0;
int used_size=0;
int flag=0;
int times=0;
int m_init();
void *m_expand(size_t size);
void m_free(void *addr);
void m_free_noncoalesce(void *addr);
void *m_malloc_first(size_t size);
void *m_malloc_best(size_t size);
void *m_coalesce_next(char *addr);
void *m_coalesce_pre(char *addr);
void *m_add_fl(char *addr);
void *m_coalesce_pre_or_add_fl(char *addr);
void *m_split(char *addr, size_t size);
void display_free();
void display_all();

double calc_time(struct timeval start, struct timeval end) {
  double start_sec = (double)start.tv_sec + (double)start.tv_usec / 1000000.0;
  double end_sec = (double)end.tv_sec + (double)end.tv_usec / 1000000.0;

  if (end_sec < start_sec) {
    return 0;
  } else {
    return end_sec - start_sec;
  }
};


unsigned long get_data_segment_size(){
  return (unsigned long)heap_size;
}


unsigned long get_data_segment_free_space_size(){
  return (unsigned long)(heap_size-used_size);
}

int m_init(){
  if((heap_start=(char *)sbrk(84))==(char *)-1){
    printf("The initialization fail\n");
    return -1;
  }
  list_start=heap_start+WSIZE;
  heap_end=(char *)sbrk(0);
  list_end=heap_end-DSIZE;
  heap_size=(int)(heap_end-heap_start);
  used_size=2*DSIZE+WSIZE;
  PUT(heap_start, PACK(8,1));//the first head
  PUT(list_start, (size_t )((char *)list_start+8));//the freelist head point to first free space
  
  PUT(HA(list_end),PACK(8,1));
  PUT(FLP(list_end),FFA);
  PUT(HA(FFA),PACK(64,0));// the first free space head
  PUT(FA(FFA),PACK(64,0));// the first free space foot
  PUT(FLN(FFA),list_end);// the first free space next pointer
  PUT(FLP(FFA),list_start);// the first free space previous pointer
  return 0;
}

void *m_expand(size_t size){
  if( ((char *)sbrk(MAX(size,CHUNKSIZE)))==(char *)-1 ){
    printf("The expand fail\n");
    abort();
  }
  char *old_heap_end=heap_end;
  char *old_list_end=list_end;
  char *pre_end=(char *)PFA(list_end);
  heap_size+=MAX(size,CHUNKSIZE);
  heap_end=(char *)sbrk(0);
  list_end=heap_end-DSIZE;
  PUT(HA(list_end),PACK(8,1));
  PUT(FLP(list_end),pre_end);
  PUT(FLN(pre_end),list_end);
  PUT(HA(old_list_end),PACK(MAX(size,CHUNKSIZE),0));
  PUT(FA(old_list_end),PACK(MAX(size,CHUNKSIZE),0));
  char *new_block=(char *)m_coalesce_pre_or_add_fl(old_list_end);
  return m_split(new_block,size);
}

void m_free(void *addr){
  PUT(HA(addr),PACK(GET_SIZE(HA(addr)),0));
  PUT(FA(addr),PACK(GET_SIZE(FA(addr)),0));
  used_size-=GET_SIZE(HA(addr));
  m_coalesce_next(m_coalesce_pre_or_add_fl((char *)addr));
}

void m_free_noncoalesce(void *addr){
  PUT(HA(addr),PACK(GET_SIZE(HA(addr)),0));
  PUT(FA(addr),PACK(GET_SIZE(FA(addr)),0));
  used_size-=GET_SIZE(HA(addr));
  m_add_fl((char *)addr);
}

void *m_malloc_best(size_t size){
  if(flag==0){
    m_init();
    flag = 1;
  }
  size=PADDING(size);
  char *current = (char *)FFA;
  char *best_fit = (char *)FFA;
  int index = 0;
  if( (size_t)GET_SIZE(HA(best_fit))>=size )
    index = 1;
  while(current!=list_end){
    if( ((size_t)GET_SIZE(HA(current))>=size) && ((size_t)GET_SIZE(HA(current))<=(size_t)GET_SIZE(HA(best_fit))) ){
      best_fit = current;
      index=1;
      if((size_t)GET_SIZE(HA(best_fit))==size)
        break;
    }
    current = (char *)NFA(current);
  }
  if(index==0){
    return m_expand(size);
  }
  else{
    if((best_fit=m_split(best_fit,size))!=NULL){
      return best_fit;
    }
    else{
      printf("The find should find the right size block, but the split find the size is too small!\n");
      abort();
    }
  }
}
  

void *m_malloc_first(size_t size){
  if(flag==0){
    m_init();
    flag = 1;
  }
  size=PADDING(size);
  char *current = (char *)FFA;
  while(current!=list_end){
    if((size_t)GET_SIZE(HA(current))>=size){
      break;
    }
    current=(char *)NFA(current);
  }
  if(current!=list_end){
    if((current=m_split(current,size))!=NULL){
      return current;
    }
    else{
      printf("The find should find the right size block, but the split find the size is too small!\n");
      abort();
    }
  }
  else{
      return m_expand(size); 
  }
}


void *m_coalesce_next(char *addr){
  assert(GET_ALLOC(HA(addr))==0);
  assert((addr!=heap_start)||(addr!=list_start)||(addr!=list_end)||(addr!=heap_end));
  if( (GET_ALLOC(HA(NEXT_BLOCK(addr)))==0)&&(addr!=(char *)EFA) ){
    char * next_addr = NEXT_BLOCK(addr);
    size_t new_size = GET_SIZE(HA(addr)) + GET_SIZE(HA(NEXT_BLOCK(addr)));
    char * pre_fl = (char *)PFA(next_addr);
    char * next_fl = (char *)NFA(next_addr);
    PUT(FLN(pre_fl),next_fl);
    PUT(FLP(next_fl),pre_fl);
    PUT(HA(addr),PACK(new_size,0));
    PUT(FA(addr),PACK(new_size,0));
  }
  return addr;
}

void *m_coalesce_pre(char *addr){
  assert(GET_ALLOC(HA(addr))==0);
  assert((addr!=heap_start)||(addr!=list_start)||(addr!=list_end)||(addr!=heap_end));
  if( (GET_ALLOC(addr-DSIZE)==0)&&(PRE_BLOCK(addr)<heap_end)&&(PRE_BLOCK(addr)>heap_start)&&(GET_ALLOC(HA(PRE_BLOCK(addr)))==0)&&(GET_SIZE(HA(PRE_BLOCK(addr)))==GET_SIZE(addr-DSIZE))&&(addr!=(char *)FFA) ){
    char *pre_addr = PRE_BLOCK(addr);
    size_t new_size = GET_SIZE(HA(addr)) + GET_SIZE(HA(PRE_BLOCK(addr)));
    char * pre_fl = (char *)PFA(addr);
    char * next_fl = (char *)NFA(addr);
    PUT(FLN(pre_fl),next_fl);
    PUT(FLP(next_fl),pre_fl);
    PUT(HA(pre_addr),PACK(new_size,0));
    PUT(FA(pre_addr),PACK(new_size,0));
    return pre_addr;
  }
  else
    return addr;
}
  
void *m_add_fl(char *addr){
  assert(GET_ALLOC(HA(addr))==0);
  assert((addr!=heap_start)||(addr!=list_start)||(addr!=list_end)||(addr!=heap_end));
  char * old_ffa = (char *)FFA;
  PUT(FLP(old_ffa),addr);
  PUT(FLN(addr),old_ffa);
  PUT(FLN(list_start),addr);
  PUT(FLP(addr),list_start);
  return addr;
}


void *m_coalesce_pre_or_add_fl(char *addr){
  assert(GET_ALLOC(HA(addr))==0);
  assert((addr!=heap_start)||(addr!=list_start)||(addr!=list_end)||(addr!=heap_end));
  if( (GET_ALLOC(addr-DSIZE)==0)&&(PRE_BLOCK(addr)<heap_end)&&(PRE_BLOCK(addr)>heap_start)&&(GET_ALLOC(HA(PRE_BLOCK(addr)))==0)&&(GET_SIZE(HA(PRE_BLOCK(addr)))==GET_SIZE(addr-DSIZE))&&(addr!=(char *)FFA) ){
    char * pre_addr = PRE_BLOCK(addr);
    size_t new_size = GET_SIZE(HA(addr)) + GET_SIZE(HA(PRE_BLOCK(addr)));
    PUT(HA(pre_addr),PACK(new_size,0));
    PUT(FA(pre_addr),PACK(new_size,0));
    return pre_addr;
  }
  else{
    char * old_ffa = (char *)FFA;
    PUT(FLP(old_ffa),addr);
    PUT(FLN(addr),old_ffa);
    PUT(FLN(list_start),addr);
    PUT(FLP(addr),list_start);
    return addr;
  }
}

void *m_split(char *addr, size_t size){
  assert(size%16==0);
  assert((addr!=heap_start)||(addr!=list_start)||(addr!=list_end)||(addr!=heap_end));
  if(GET_SIZE(HA(addr))<size){
    //printf("The block you find for split is too small  !");
    return NULL;
  }
  else if((GET_SIZE(HA(addr)))==size){ 
    PUT(HA(addr),PACK(size,1));
    PUT(FA(addr),PACK(size,1));
    used_size+=size;
    char *next_fl=(char *)NFA(addr);
    char *pre_fl=(char *)PFA(addr);
    PUT(FLN(pre_fl),next_fl);
    PUT(FLP(next_fl),pre_fl);
    return addr;
  } 
  else{
    size_t new_size=GET_SIZE(HA(addr))-size;
    PUT(HA(addr),PACK(size,1));
    PUT(FA(addr),PACK(size,1));
    used_size+=size;
    char *next_fl=(char *)NFA(addr);
    char *pre_fl=(char *)PFA(addr);
    char *rest_addr=NEXT_BLOCK(addr);
    PUT(FLN(pre_fl),rest_addr);
    PUT(FLP(rest_addr),pre_fl);
    PUT(FLP(next_fl),rest_addr);
    PUT(FLN(rest_addr),next_fl);
    PUT(HA(rest_addr),PACK(new_size,0));
    PUT(FA(rest_addr),PACK(new_size,0));
    return addr;
  }
}

void display_free(){
  char *current=(char *)FFA;
  int i=0;
  while(current!=list_end){
    printf("=========================\n");
    printf("%d free block addr= %p\n",i,current);
    printf("%d free block size= %zu\n",i,GET_SIZE(HA(current)));
    printf("%d free block alloc=%zu\n",i,GET_ALLOC(HA(current)));
    current=(char *)NFA(current);
    i++;
  }
  printf("=========================\n");
}

void display_all(){
  char *current=(char *)(list_start+DSIZE);
  int i=0;
  while(current!=list_end){
    printf("=========================\n");
    printf("%d block addr= %p\n",i,current);
    printf("%d block size= %zu\n",i,GET_SIZE(HA(current)));
    printf("%d block alloc=%zu\n",i,GET_ALLOC(HA(current)));
    current=NEXT_BLOCK(current);
    i++;
  }
  printf("=========================\n");
}



int main(int argc, char *argv[])
{
  int i, j;
  int *array[NUM_ITEMS];
  int *spacing_array[NUM_ITEMS];
  unsigned long data_segment_size;
  unsigned long data_segment_free_space;
  struct timeval start_time, end_time;

  if (NUM_ITEMS < 10000) {
    printf("Error: NUM_ITEMS must be >= 1000\n");
    return -1;
  } //if

  for (i=0; i < NUM_ITEMS; i++) {
    array[i] = (int *)MALLOC(ALLOC_SIZE);
    spacing_array[i] = (int *)MALLOC(ALLOC_SIZE);
  } //for i

  for (i=0; i < NUM_ITEMS; i++) {
    FREE(array[i]);
  } //for i

  //Start Time
  gettimeofday(&start_time, NULL);

  for (i=0; i < NUM_ITERS; i++) {
    for (j=0; j < 1000; j++) {
      array[j] = (int *)MALLOC(ALLOC_SIZE);
    } //for j

    for (j=1000; j < NUM_ITEMS; j++) {
      array[j] = (int *)MALLOC(ALLOC_SIZE);
      FREE(array[j-1000]);

      if ((i==NUM_ITERS/2) && (j==NUM_ITEMS/2)) {
	//Record fragmentation halfway through (try to repsresent steady state)
	data_segment_size = get_data_segment_size();
	data_segment_free_space = get_data_segment_free_space_size();
      } //if
    } //for j

    for (j=NUM_ITEMS-1000; j < NUM_ITEMS; j++) {
      FREE(array[j]);
    } //for j
  } //for i

  //Stop Time
  gettimeofday(&end_time, NULL);

  double elapsed_sec = calc_time(start_time, end_time);
  printf("Execution Time = %f seconds\n", elapsed_sec);
  printf("Fragmentation  = %f\n", (float)data_segment_free_space/(float)data_segment_size);
  for (i=0; i < NUM_ITEMS; i++) {
    FREE(spacing_array[i]);
  }
  
  return 0;
}




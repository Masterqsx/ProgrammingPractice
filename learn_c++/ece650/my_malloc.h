#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>

#define WSIZE 4
#define DSIZE 8
#define MINSIZE 16
#define CHUNKSIZE (1<<7)
#define PADDING(size) (((size+4)/16+1)*16)
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
/*
char *heap_start=NULL;
char *list_start=NULL;
char *list_end=NULL;
char *heap_end=NULL;
//char *real_start=NULL;
int heap_size=0;
int used_size=0;
*/
int m_init();
void *m_expand(size_t size);
void m_free(void *addr);
void *m_malloc_first(size_t size);
void *m_coalesce_next(char *addr);
void *m_coalesce_pre_or_add_fl(char *addr);
void *m_split(char *addr, size_t size);
void display_free();
void display_all();



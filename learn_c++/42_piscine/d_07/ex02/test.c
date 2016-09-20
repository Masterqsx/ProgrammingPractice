#include<stdio.h>
#include<stdlib.h>

int ft_ultimate_range(int **range,int min, int max);

int main(int argc,char **argv){
	int *s=NULL;
	printf("%d\n",ft_ultimate_range(&s,atoi(argv[1]),atoi(argv[2])));
	for(int i=0;i<atoi(argv[2])-atoi(argv[1]);i++)
		printf("%d\n",s[i]);
	return 0;
}

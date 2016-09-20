#include<stdio.h>
#include<string.h>
#include<stdlib.h>
unsigned int ft_strlcpy(char *,char *,unsigned int);

int main(int argc,char **argv){
	char s0[20];
	char s1[20];
	printf("%lu\n",strlcpy(s0,argv[1],atoi(argv[2])));
	printf("%s\n",s0);
	printf("%u\n",ft_strlcpy(s1,argv[1],atoi(argv[2])));
	printf("%s\n",s1);
	return 0;
}

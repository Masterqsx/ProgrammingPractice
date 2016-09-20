#include<stdio.h>
#include<string.h>
#include<stdlib.h>
unsigned int ft_strlcat(char *,char *,unsigned int);

int main(int argc,char **argv){
	char s0[20];
	char s1[20];
	strcpy(s0,argv[1]);
	strcpy(s1,argv[1]);
	printf("%lu\n",strlcat(s0,argv[2],atoi(argv[3])));
	printf("%s\n",s0);
	printf("%u\n",ft_strlcat(s1,argv[2],atoi(argv[3])));
	printf("%s\n",s1);
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* ft_strncat(char *dest,char* src,int nb);

int main(int argc, char** argv){
	char s1[20];
	char s2[20];
	strcpy(s1,argv[1]);
	strcpy(s2,argv[1]);
	printf("%s\n",ft_strncat(s1,argv[2],atoi(argv[3])));
	printf("%s\n",strncat(s2,argv[2],atoi(argv[3])));
	return 0;
}

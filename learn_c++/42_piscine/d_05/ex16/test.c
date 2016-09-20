#include<stdio.h>
#include<string.h>
char* ft_strcat(char *dest,char* src);

int main(int argc, char** argv){
	char s1[20];
	char s2[20];
	strcpy(s1,argv[1]);
	strcpy(s2,argv[1]);
	printf("%s\n",ft_strcat(s1,argv[2]));
	printf("%s\n",strcat(s2,argv[2]));
	return 0;
}

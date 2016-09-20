#include<stdio.h>
#include<stdlib.h>

char *ft_strdup(char *src);

int main(int argc,char **argv){
	char *s=ft_strdup(argv[1]);
	printf("%s\n",s);
	free(s);
	return 0;
}

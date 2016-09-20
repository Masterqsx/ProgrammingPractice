#include <stdio.h>
#include <stdlib.h>
char **ft_split_whitespaces(char *);

int main(int argc,char **argv){
	char **re=ft_split_whitespaces(argv[1]);
	if(!re) return 0;
	for(int i=0;re[i]!=0;i++){
		printf("%s\n",re[i]);
		free(re[i]);
	}
	printf("%s\n",argv[1]);
	free(re);
	return 0;
}

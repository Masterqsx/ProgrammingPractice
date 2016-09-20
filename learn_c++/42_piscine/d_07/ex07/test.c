#include <stdio.h>
#include <stdlib.h>
char **ft_split(char *,char *);

int main(int argc,char **argv){
	char **re=ft_split(argv[1],argv[2]);
	if(!re) return 0;
	for(int i=0;re[i]!=0;i++){
		printf("%s\n",re[i]);
		free(re[i]);
	}
	free(re);
	return 0;
}

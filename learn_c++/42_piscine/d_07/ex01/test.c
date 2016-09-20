#include <stdio.h>
#include <stdlib.h>

int* ft_range(int min, int max);

int main(int argc, char **argv){
	int min=atoi(argv[1]),max=atoi(argv[2]);
	int *re=ft_range(min,max);
	for(int i=0;i<max-min;i++){
		printf("%d\n",re[i]);
	}
	free(re);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int ft_button(int i, int j, int k);

int main(int argc, char **argv){
	if(argc > 3)
		printf("%d\n",ft_button(atoi(argv[1]),atoi(argv[2]),atoi(argv[3])));	return 0;
}


#include<stdio.h>
#include<stdlib.h>
unsigned int ft_active_bits(int value);

int main(int argc, char **argv){
	if (argc >1)
		printf("%u\n",ft_active_bits(atoi(argv[1])));
	return 0;
}

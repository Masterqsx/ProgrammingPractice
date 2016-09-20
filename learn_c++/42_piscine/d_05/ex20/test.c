#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int ft_putchar(char c){
	write(1, &c, 1);
	return 0;
}

void ft_putnbr_base(int,char*);

int main(int argc,char **argv){
	ft_putnbr_base(atoi(argv[1]),argv[2]);
	return 0;
}

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int ft_putchar(char c){
	write(1, &c, 1);
	return 0;
}

void *ft_print_memory(void *addr,unsigned int size);

int main(){
	char s1[]="Salut les aminch \n I think you should have";
	ft_print_memory(s1,30);
	return 0;
}

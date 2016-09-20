#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void ft_putstr_non_printable(char *str);
int ft_putchar(char c){
	write(1,&c,1);
	return 0;
}

int main(int argc,char** argv)
{
	ft_putstr_non_printable("\036abc");
	return 0;
}

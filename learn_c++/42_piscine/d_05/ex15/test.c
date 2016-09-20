#include<stdio.h>

int ft_str_is_printable(char *str);

int main(int argc,char **argv){
	printf("%d\n",ft_str_is_printable("abc\010"));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char **ft_split_whitespaces(char *);
void ft_print_words_tables(char **tab);
int ft_putchar(char c){
	write(1, &c, 1);
	return 0;
}
int main(int argc,char **argv){
	char **re=ft_split_whitespaces(argv[1]);
	ft_print_words_tables(re);
	free(re);
	return 0;
}

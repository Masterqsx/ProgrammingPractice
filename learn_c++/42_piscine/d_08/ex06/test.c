#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_par.h"
int ft_putchar(char c){
	write(1, &c, 1);
	return 0;
}

int main(int argc, char **argv){
	ft_show_tab(ft_param_to_tab(argc, argv));
	return 0;
}

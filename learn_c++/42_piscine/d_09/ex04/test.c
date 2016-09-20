#include<stdio.h>

char *ft_rot42(char *str);

int main(int argc, char **argv){
	if (argc > 1)
		printf("%s\n",ft_rot42(argv[1]));
	return 0;
}

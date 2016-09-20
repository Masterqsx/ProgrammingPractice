#include <stdio.h>
#include <stdlib.h>
char *ft_join(char **tab,char *sep);

int main(int argc, char **argv){
	char **sa=(char **)malloc(4 * sizeof(*sa));
	sa[0] = argv[1];
	sa[1] = argv[2];
	sa[2] = argv[3];
	sa[3] = 0;
	if(argc > 1){
		printf("%s\n",ft_join(sa,"||"));
	}
	return 0;
}

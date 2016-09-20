#include <stdio.h>
#include <stdlib.h>

void ft_sort_wordtab(char **tab);

int main(int argc, char **argv){
	argc=2;
	char **a = (char **)malloc(4 * sizeof(*a));
	a[0] = argv[1];
	a[1] = argv[2];
	a[2] = argv[3];
	a[3] = 0;
	ft_sort_wordtab(a);
	for(int i=0;i<3;i++)
		printf("%s\n",a[i]);
	return 0;
}

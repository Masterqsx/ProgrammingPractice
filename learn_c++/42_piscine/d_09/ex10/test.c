#include <stdio.h>
#include <stdlib.h>
void ft_scrambler(int ***a, int *b, int *******c, int ****d);

int main(int argc, char **argv){
	if(argc > 4){
		int a=atoi(argv[1]);
		int *sa=&a;
		int **ssa=&sa;
		int b=atoi(argv[2]);
		int c=atoi(argv[3]);
		int *sc=&c;
		int **ssc=&sc;
		int ***sssc=&ssc;
		int ****ssssc=&sssc;
		int *****sssssc=&ssssc;
		int ******ssssssc=&sssssc;
		int d=atoi(argv[4]);
		int *sd=&d;
		int **ssd=&sd;
		int ***sssd=&ssd;
		ft_scrambler(&ssa,&b,&ssssssc,&sssd);
		printf("%d %d %d %d\n",a,b,c,d);
	}
	return 0;
}

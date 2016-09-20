#include <stdio.h>
#include <stdlib.h>
int ft_compact(char **tab,int length);

int main(){
	char a[10]="abcdefghij";
	char **b = (char **)malloc(10*sizeof(*b));
	for(int i=0;i<10;i++)
		b[i]=&a[i];
	b[2]=0;
	printf("%d\n",ft_compact(b,10));
	/*for(int i=0;i<8;i++)
		printf("%c\n",b[i][0]);
	*/printf("%c",b[8][0]);
	return 0;
}

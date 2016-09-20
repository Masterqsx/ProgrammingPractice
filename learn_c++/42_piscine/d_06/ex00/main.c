#include<stdio.h>

void ft_swap(int*,int*);
int main(){
	int i=1,j=2;
	ft_swap(&i,&j);
	printf("%d %d\n",i,j);
	return 0;
}

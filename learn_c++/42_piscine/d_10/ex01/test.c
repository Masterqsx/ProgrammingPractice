#include <stdio.h>
void	ft_foreach(int *,int,void (*)(int));

void	ft(int n){
	printf("%d\n",n);
}

int main(){
	int tab[5]={1,2,3,4,5};
	ft_foreach(tab,5,&ft);
	return 0;
}


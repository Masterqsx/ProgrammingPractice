#include <stdio.h>
int*	ft_map(int *,int,int (*)(int));

int	ft(int n){
	return (n+1);
}

int main(){
	int tab[5]={1,2,3,4,5};
	int *re=ft_map(tab,5,&ft);
	if(!re)
		return (1);
	for(int i=0;i<5;i++)
		printf("%d\n",re[i]);
	return 0;
}


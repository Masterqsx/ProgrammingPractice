#include <stdio.h>
#include <stdlib.h>
int	ft_is_sort(int *,int ,int (*)(int, int));

int	ft(int i, int j){
	return i - j;
}

int main(){
	int a[]={2,1,3,4,5};
	printf("%d\n", ft_is_sort(a, 5, &ft));
	return 0;
}


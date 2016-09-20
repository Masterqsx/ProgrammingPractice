#include <stdio.h>
#include <stdlib.h>
int	ft_any(char**,int (*)(char*));

int	ft(char *p){
	if(p)
		return (1);
	else
		return (0);
}

int main(){
	//char s1[]="abc";
	//char s2[]="abcss";
	char **a1=(char **)malloc(2*sizeof(*a1));
	a1[0]=0;a1[1]=0;
	printf("%d\n", ft_any(a1,0));

	return 0;
}


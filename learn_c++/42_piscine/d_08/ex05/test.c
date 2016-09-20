#include <stdio.h>
#include "ft_stock_par.h"

int main(int argc, char **argv){
	t_stock_par *re = 0;
	re = ft_param_to_tab(argc,argv);
	int i=0;
	if (!re){
		printf("not working\n");
		return (0);
	}
	while (re[i].str!=0){
		printf("%d\n",re[i].size_param);
		printf("%s\n",re[i].str);
		printf("%s\n",re[i].copy);
		for(int j=0;re[i].tab[j]!=0;j++){
			printf("inside :%s\n",re[i].tab[j]);
		}
		i++;
	}
	return 0;
}

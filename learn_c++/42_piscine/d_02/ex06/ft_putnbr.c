/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:27:39 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 19:17:26 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char);

void ft_putnchar(char* str,int n){
  int i=0;
  while(i<n){
    ft_putchar(str[i]);
    i++;
  }
}

void ft_putnbr(int nb){ 
  if(nb==0) ft_putchar('0');
  if(nb==-2147483648) ft_putnchar("-2147483648",11);
  if(nb==0||nb==-2147483648) return;
  if(nb<0){
    ft_putchar('-');
    nb*=-1;
  }
  char ans[10]={'a','a','a','a','a','a','a','a','a','a'};
  int re = 0,cur=9;
  while((re = nb%10)!=0||nb/10!=0){
    ans[cur]=re+'0';
    nb/=10;
    cur--;
  }
  while(cur<10){
    if(ans[cur]!='a') ft_putchar(ans[cur]);
    cur++;
  }
}

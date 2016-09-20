/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:37:51 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 21:00:51 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void quicksort(int*,int,int);
void bubblesort(int*,int);
void ft_sort_integer_table(int* tab,int size)
{
    if(!tab) return;
    bubblesort(tab,size);
  //quicksort(tab,0,size-1);
}

void bubblesort(int* tab,int size)
{
    int end,i,last_swap;
  
    end = size;
    while(end > 1)
    {
        i = 0;
        last_swap = 0;
        while(i + 1 < end)
        {
            if(tab[i]>tab[i+1])
            {
            tab[i] ^= tab[i + 1] ^ (tab[i + 1] = tab[i]);
            last_swap = i + 1;
            }
            i++;
        }
        end = last_swap;
    }
}
/*            
void quicksort(int* tab,int l,int h){
  if(l >= h) return;
  int i,j,k,flag; 
  i = l;
  j = h;
  k = l;
  flag = 1;
  while(i < j){
    if(flag){
      if(tab[j] <= tab[k]){
        flag = 0;
        tab[j] ^= tab[k] ^ (tab[k] = tab[j]);
        k = j;
        i++;
      }
      else j--;
    }
    else{
      if(tab[i] >= tab[k]){
        flag = 1;
        tab[i] ^= tab[k] ^ (tab[k] = tab[i]);
        k = i;
        j--;
      }
      else i++;
    }
  }
  quicksort(tab,l,k-1);
  quicksort(tab,k+1,h);
}
*/


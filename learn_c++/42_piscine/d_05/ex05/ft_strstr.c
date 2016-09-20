/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:03:36 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 19:50:41 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULLCHECK_BIG if(!str) return 0
#define NULLCHECK_LIT if(!to_find) return str
#define EMPTYCHECK if(to_find[0]=='\0') return str
#define END_TO_FIND if(to_find[j]=='\0') return str+i
#define END_STR else if(str[k]=='\0') return 0;
#define PLUS j++;k++

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	NULLCHECK_BIG;
	NULLCHECK_LIT;
	i = 0;
	j = 0;
	EMPTYCHECK;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j = 0;
			k = i;
			while (str[k] != '\0' && to_find[j] != '\0' && to_find[j] == str[k])
			{
				PLUS;
			}
			END_TO_FIND;
			END_STR;
		}
		i++;
	}
	return (0);
}

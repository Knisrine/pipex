/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:21:35 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/22 02:46:59 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int len;
	int i;
	int k;
	len = ft_strlen(to_find);
	
	i = 0;
	k = 0;
	while (str[i])
	{
		while(str[i + k] == to_find[k])
		{		
			k++;
			if (k == len)
			{
				return (&str[i + k]);
				printf("%s\n", str);
			}
		}
		i++;
	}
	return NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:35:15 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 17:37:35 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_count_word(char const *st, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (st[i] != '\0')
	{
		if (st[i] == c)
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

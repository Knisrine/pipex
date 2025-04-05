/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:22:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 17:41:38 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*make_str(char *str, int len)
{
	int		i;
	char	*st;

	i = 0;
	st = malloc(sizeof(char) * (len + 1));
	if (!st)
		return (NULL);
	while (i < len)
	{
		st[i] = str[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

static void	quot_case(t_data *data, char *s)
{
	data->i++;
	data->start = data->i;
	while (s[data->i] && (s[data->i] != '\'' && s[data->i] != '\"'))
		data->i++;
	if (data->i > data->start)
		data->tmp = make_str(s + data->start, data->i - data->start);
	data->result[data->j++] = data->tmp;
}

static int	nrml_case(t_data *data, char *s)
{
	data->tmp = make_str(s + data->start, data->i - data->start);
	if (!data->tmp)
	{
		data->j--;
		while (data->j >= 0)
		{
			free(data->result[data->j]);
			data->j--;
		}
		return (0);
	}
	data->result[data->j++] = data->tmp;
	return (1);
}

static int	split_string(t_data *data, char *s, char c)
{
	while (s[data->i] != '\0')
	{
		while (s[data->i] == c)
			data->i++;
		data->start = data->i;
		if (s[data->i] == '\'' || s[data->i] == '\"')
		{
			quot_case(data, s);
			return (1);
		}
		else
		{
			while (s[data->i] != '\0' && s[data->i] != c)
				data->i++;
			if (data->i > data->start)
			{
				if (nrml_case(data, s) == 0)
					return (free(data->result), 0);
			}
		}
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	t_data	data;

	if (!s)
		return (NULL);
	data.word_count = ft_count_word(s, c);
	data.result = (char **)malloc(sizeof(char *) * (data.word_count + 1));
	if (!(data.result))
		return (NULL);
	data.i = 0;
	data.j = 0;
	if (!split_string(&data, s, c))
		return (NULL);
	data.result[data.j] = NULL;
	return (data.result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:29:08 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/08 13:16:21 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **s)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (ft_strstr(s[i], "PATH="))
		{
			str = ft_strdup(ft_strstr(s[i], "PATH="));
			break ;
		}
		i++;
	}
	return (str);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*valid_path(char **env, char *cmmd)
{
	char	**path;
	char	*p;
	t_var	v;

	p = NULL;
	v.full_path = get_path(env);
	if (!v.full_path)
	{
		write(2, "PATH Not Found!\n", 17);
		exit(1);
	}
	path = ft_split(v.full_path, ':');
	free(v.full_path);
	v.i = 0;
	while (path[v.i])
	{
		p = ft_strjoin(path[v.i], "/");
		p = ft_strjoin(p, cmmd);
		if (!access(p, X_OK))
			return (free_path(path), p);
		free(p);
		v.i++;
	}
	free_path(path);
	return (NULL);
}

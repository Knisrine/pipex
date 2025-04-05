/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:29:08 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 17:49:56 by nikhtib          ###   ########.fr       */
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
	while (*path)
		free(*path++);
}

char	*valid_path(char **env, char *cmmd)
{
	char	*full_path;
	char	**path;
	char	*p;

	p = NULL;
	full_path = get_path(env);
	path = ft_split(full_path, ':');
	free(full_path);
	while (*path)
	{
		p = ft_strjoin(*path, "/");
		p = ft_strjoin(p, cmmd);
		if (!access(p, X_OK))
		{
			free_path(path);
			return (p);
		}
		free(p);
		path++;
	}
	//////check leaks
	free_path(path);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:14:05 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 19:02:11 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_process(t_var *v, char *arg1)
{
	int	infile;

	infile = open(arg1, O_RDONLY);
	if (infile < 0)
	{
		perror("Failed to open input file");
		close(v->fd[0]);
		close(v->fd[1]);
		exit(1);
	}
	dup2(infile, 0);
	dup2(v->fd[1], 1);
	close(infile);
	close(v->fd[0]);
	close(v->fd[1]);
}

void	check_fcmmd(t_var *v, char *arg, char **env)
{
	char	*p;

	v->cmmd1 = ft_split(arg, ' ');
	p = valid_path(env, v->cmmd1[0]);
	if (!v->cmmd1 || !v->cmmd1[0])
	{
		perror("v->cmmd1 not exist\n");
		exit(1);
	}
	if (!access(v->cmmd1[0], X_OK))
		v->path = ft_strdup(v->cmmd1[0]);
	else if (p)
	{
		v->path = ft_strdup(p);
		free(p);
	}
	else
	{
		perror("Command not found\n");
		free_data(v->cmmd1)ccc
	}
}

void	s_process(t_var *v, char *arg2)
{
	v->outfile = open(arg2, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (v->outfile == -1)
	{
		perror("Failed to open output file");
		close(v->fd[0]);
		close(v->fd[1]);
		exit(1);
	}
	dup2(v->fd[0], 0);
	dup2(v->outfile, 1);
	close(v->outfile);
	close(v->fd[0]);
	close(v->fd[1]);
}

void	check_scmmd(t_var *v, char *arg, char **env)
{
	v->cmmd2 = ft_split(arg, ' ');
	v->p = valid_path(env, v->cmmd2[0]);
	if (!v->cmmd2 || !v->cmmd2[0])
	{
		perror("Scnd command not found\n");
		exit(1);
	}
	if (!access(v->cmmd2[0], X_OK))
		v->path = ft_strdup(v->cmmd2[0]);
	else if (v->p)
	{
		v->path = ft_strdup(v->p);
		free(v->p);
	}
	else
	{
		perror("Command not found");
		free_data(v->cmmd2);
		exit(1);
	}
}

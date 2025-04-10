/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:14:05 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/08 15:29:41 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_process(t_var *v, char *arg1)
{
	int	infile;

	infile = open(arg1, O_RDONLY);
	if (infile < 0)
	{
		write(2, "Failed to open input file", 26);
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

static void	check_p(char *p)
{
	if (!p)
	{
		write(2, "PATH Not Found \n", 17);
		exit(1);
	}
}

void	check_fcmmd(t_var *v, char *arg, char **env)
{
	v->cmmd1 = ft_split(arg, ' ');
	v->p = valid_path(env, v->cmmd1[0]);
	check_p(v->p);
	if (!v->cmmd1 || !v->cmmd1[0])
	{
		write(2, "Cmmd1 Not Found !\n", 17);
		free_data(v->cmmd1);
		exit(1);
	}
	if (!access(v->cmmd1[0], X_OK))
		v->path = ft_strdup(v->cmmd1[0]);
	else if (v->p)
		v->path = ft_strdup(v->p);
	free(v->p);
}

void	s_process(t_var *v, char *arg2)
{
	v->outfile = open(arg2, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (v->outfile == -1)
	{
		write(2, "Failed to open output file", 27);
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
	check_p(v->p);
	if (!v->cmmd2 || !v->cmmd2[0])
	{
		write(2, "Cmmd2 not found !\n", 24);
		free_data(v->cmmd2);
		exit(1);
	}
	if (!access(v->cmmd2[0], X_OK))
		v->path = ft_strdup(v->cmmd2[0]);
	else if (v->p)
		v->path = ft_strdup(v->p);
	free(v->p);
}

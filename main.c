/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:29:18 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 18:51:05 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	f_child(t_var v, char **av, char **env)
{
	f_process(&v, av[1]);
	check_fcmmd(&v, av[2], env);
	if (execve(v.path, v.cmmd1, env) == -1)
		ex_error(&v);
}

static void	s_child(t_var v, char **av, char **env)
{
	s_process(&v, av[4]);
	check_scmmd(&v, av[3], env);
	execve(v.path, v.cmmd2, env);
	perror("execve failed for second command");
	ex_error(&v);
}
// void	ff(void)
// {
// 	system("leaks pipex");
// }
int	main(int ac, char **av, char **env)
{
	t_var	v;
	// atexit(ff);
	v.cmmd1 = NULL;
	v.cmmd2 = NULL;
	v.p = NULL;
	if (ac != 5)
		return (0);
	if (pipe(v.fd) == -1)
		return (perror("pipe failed\n"), 1);
	v.id = fork();
	if (v.id == 0)
		f_child(v, av, env);
	v.id2 = fork();
	if (v.id2 == 0)
		s_child(v, av, env);
	close_fd(&v);
	exit_state(v);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:58:58 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/08 15:09:23 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ex_error(t_var *v)
{
	write(2, "execve failed for the command\n", 34);
	free(v->path);
	free_data(v->cmmd1);
	free_data(v->cmmd2);
	exit(1);
}

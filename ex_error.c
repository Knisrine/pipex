/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:58:58 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 17:59:23 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ex_error(t_var *v)
{
	perror("execve failed for second command");
	free(v->path);
	free_data(v->cmmd2);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:36:37 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 17:59:29 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_state(t_var v)
{
	int	stat1;
	int	stat2;

	waitpid(v.id, &stat1, 0);
	waitpid(v.id2, &stat2, 0);
	if (WIFEXITED(stat1) && WIFEXITED(stat2))
		return ;
	else
		perror("Exit State : Incomplete or Incorrect Output\n");
}

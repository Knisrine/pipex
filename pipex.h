/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:50:50 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/05 17:57:13 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**result;
	int		i;
	int		j;
	int		start;
	int		word_count;
	char	*tmp;
}			t_data;

typedef struct s_variables
{
	char	*path;
	char	**cmmd1;
	char	**cmmd2;
	int		outfile;
	int		fd[2];
	int		id;
	int		id2;
	char	*p;
}		t_var;

char		*valid_path(char **env, char *cmmd);
char		**ft_split(char *s, char c);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strjoin(char *s1, char *s2);
void		free_data(char **str);
char		*ft_strdup(char *s1);
int			ft_strlen(char *str);
void		exit_state(t_var v);
void		close_fd(t_var *v);
void		ex_error(t_var *v);
int			ft_count_word(char const *st, char c);
void		f_process(t_var *v, char *arg1);
void		s_process(t_var *v, char *arg2);
void		check_fcmmd(t_var *v, char *arg, char **env);
void		check_scmmd(t_var *v, char *arg, char **env);
#endif
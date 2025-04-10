/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:50:50 by nikhtib           #+#    #+#             */
/*   Updated: 2025/04/08 15:11:00 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
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
	char	*full_path;
	char	*path;
	char	**cmmd1;
	char	**cmmd2;
	int		outfile;
	int		fd[2];
	int		id;
	int		id2;
	char	*p;
	int		i;
}		t_var;

void		check_fcmmd(t_var *v, char *arg, char **env);
void		check_scmmd(t_var *v, char *arg, char **env);
int			ft_count_word(char const *st, char c);
char		*ft_strstr(char *str, char *to_find);
char		*valid_path(char **env, char *cmmd);
void		f_process(t_var *v, char *arg1);
void		s_process(t_var *v, char *arg2);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *s, char c);
void		free_data(char **str);
char		*ft_strdup(char *s1);
int			ft_strlen(char *str);
void		ex_error(t_var *v);
#endif
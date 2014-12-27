/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:27:35 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/27 22:10:10 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
		

typedef struct		s_alias
{
	char			*input;
	char			*output;
	struct s_alias	*next;
}					t_alias;

char				*ft_prompt(char **env, int ret);
char				**ft_get_path(char **env);
void				ft_exit(int ret);
void				ft_env(char **env);
int					ft_get_command(char *command, char **path, char ***env);
void				ft_repl(char **env, char **path);
int					ft_cd(char **env, char **path, char *dir);
char				*ft_pwd(void);
void				ft_clear(void);
int					ft_get_env(char **env, char *name);
int					ft_setenv(char ***env, char *xport);
char				*ft_subc(char *s, char c);
int					ft_unsetenv(char ***env, char *unset);
char				*ft_get_home(char **env);
char				*ft_get_bin(char *command, char **path);
int					ft_exec(char *bin, char *command, char **env);
char				*ft_sub_space(char *s);
char				*get_first_word(char *command);
char				*ft_fuckit(char *s);

#endif

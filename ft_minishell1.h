/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:27:35 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 06:31:40 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
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
int					ft_get_command(char *command, char **path, char ***env, t_alias **alias);
void				ft_repl(char **env, char **path, t_alias **alias);
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
int					ft_isonlyspace(char *s);

t_alias				*new_alias(char *input, char *output);
t_alias				*push_alias(t_alias *alias, char *input, char *output);
char				*get_output(t_alias *alias, char *input);
char				*ft_tabjoin(char **tab);
char				*translate_alias(t_alias **alias, char *command);
void				print_alias(t_alias *alias);
t_alias				*ft_add_alias(char *command, t_alias **alias);
void				ft_minishellrc(t_alias **alias, char **path, char ***env);
#endif

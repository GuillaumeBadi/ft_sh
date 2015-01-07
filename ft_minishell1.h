/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:27:35 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:37:23 by gbadi            ###   ########.fr       */
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
# include <termios.h>
		
# define UP 1
# define DOWN 2

typedef struct		s_alias
{
	char			*input;
	char			*output;
	struct s_alias	*next;
}					t_alias;

typedef struct		s_list
{
	char			*entry;
	struct s_list	*next;
}					t_list;

char				*ft_prompt(char **env, int ret, t_list **history);
char				**ft_get_path(char **env);
void				ft_exit(int ret);
void				ft_env(char **env);
int					ft_get_command(char *command, char ***env, t_alias **alias, t_list **history);
void				ft_repl(char **env, t_alias **alias, t_list **history);
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
void				ft_minishellrc(t_alias **alias, char ***env, t_list **history);
char				**ft_split_custom(char *str);
char				*ft_last_history();
int					exec_commands(char ***env, t_alias **alias, char **set, t_list **history);
int					ft_strchr2(char const *s, int c);
char				*gnl(int fd, char **env, int ret, t_list **history);
void				ft_print_prompt(int r, char **env);

t_list				*new_list(void);
t_list				*push_list(t_list *list, char *entry);
char				*get_index(t_list *list, int index);
t_list				*write_history(char *cmd, t_list **list);
char				*retrieve_history(t_list *list, int direction);
int					list_len(t_list *list);
char				**ft_strsplit_whitespace(char *s);

#endif

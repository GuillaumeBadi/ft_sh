/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:26:24 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 20:30:48 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

#define COMMAND_IS(x) ft_strequ(get_first_word(tr), (x))

int		ft_is_executable(char *p)
{
	return (access(ft_strsplit(p, ' ')[0], X_OK) == 0 && ft_strlen(p) > 2);
}

char	*translate_home(char *cmd, char **env)
{
	char	*home;
	char	*s1;
	char	*s2;

	home = ft_get_home(env);
	s1 = ft_subc(cmd, '~');
	s1 = ft_strjoin(s1, home);
	s2 = ft_strchr(cmd, '~') + 1;
	s1 = ft_strjoin(s1, s2);
	return (s1);
}

int		ft_builtin(char *tr, char ***e, t_alias **alias)
{
	if (COMMAND_IS("exit"))
	{
		ft_putendl("Bye !");
		exit(0);
	}
	else if (COMMAND_IS("pwd"))
		ft_putendl(ft_pwd());
	else if (COMMAND_IS("env"))
		ft_env(*e);
	else if (COMMAND_IS("cd"))
		return (ft_cd(*e, ft_strtrim(ft_fuckit(tr + 2))));
	else if (COMMAND_IS("alias"))
		*alias = ft_add_alias(tr + 6, alias);
	else if (COMMAND_IS("export"))
		return (ft_setenv(e, ft_strtrim(tr + 6)));
	else if (COMMAND_IS("unset"))
		return (ft_unsetenv(e, tr + 5));
	else
		return (-1);
	return (0);
}

int		ft_get_command(char *command, char ***env, t_alias **alias, t_list **h)
{
	int			ret;
	char		*bin;
	char		*tr;

	ret = -1;
	command = ft_strtrim(ft_fuckit(command));
	if (ft_strchr(command, '~') != NULL)
		command = translate_home(command, *env);
	if (ft_strchr(command, ';') != NULL && !ft_strnequ(command, "alias", 5))
		return (exec_commands(env, alias, command, h));
	if (!ft_strnequ(command, "alias", 5))
		*h = write_history(command, h, *env);
	tr = translate_alias(alias, command);
	if (!ft_strequ(tr, command))
		ret = ft_get_command(tr, env, alias, h);
	else if ((ret = ft_builtin(tr, env, alias)) != -1)
		;
	else if ((bin = ft_get_bin(tr, ft_get_path(*env))) != NULL)
		ret = ft_exec(bin, tr, *env);
	else if (ft_is_executable(tr))
		ret = ft_exec(ft_strsplit(tr, ' ')[0], tr, *env);
	else
		ft_putendl(ft_strjoin("Minishell One: command not found: ", tr));
	return (ret);
}

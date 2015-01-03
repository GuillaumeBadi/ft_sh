/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:26:24 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 06:42:53 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		ft_is_executable(char *path)
{
	return (access(ft_strsplit(path, ' ')[0], X_OK) == 0);
}

int		ft_get_command(char *command, char **path, char ***env, t_alias **alias)
{
	int			ret;
	char		*bin;

	ret = 0;
	command = ft_strtrim(ft_fuckit(command));
	command = translate_alias(alias, command);
	if (ft_strlen(ft_strtrim(command)) == 0)
		ret = 0;
	else if (ft_strnequ(command, "exit", 4))
		ft_exit(0);
	else if (ft_strnequ(command, "pwd", 3))
		ft_putendl(ft_pwd());
	else if (ft_strnequ(command, "env", 3))
		ft_env(*env);
	else if (ft_strnequ(command, "clear", 5))
		ft_clear();
	else if (ft_strnequ(command, "alias", 5))
		*alias = ft_add_alias(command + 6, alias);
	else if (ft_strnequ(command, "cd", 2))
	{
		if (ft_strlen(ft_strtrim(command)) > 2)
			ret = ft_cd(*env, path, ft_strtrim(command + 2));
		else
			ret = ft_cd(*env, path, NULL);
	}
	else if (ft_strnequ(command, "export", 6))
	{
		if (ft_strlen(ft_strtrim(command)) > 6)
			ret = ft_setenv(env, ft_strtrim(command + 6));
		else
			ret = -1;
	}
	else if (ft_strnequ(command, "unset", 5))
		ret = ft_unsetenv(env, command + 5);
		//ret = ft_unsetenv(env, ft_strtrim(command + 5));

	else if ((bin = ft_get_bin(command, path)) != NULL)
	{
		ret = ft_exec(bin, command, *env);
	}
	else if (ft_is_executable(command))
	{
		ret = ft_exec(ft_strsplit(command, ' ')[0], command, *env);
		return (0);
	}
	else if (ft_strcmp(ft_strtrim(command), ""))
	{
		ft_putendl(ft_strjoin("Minishell One: command not found: ", command));
		ret = -1;
	}
	path = path;
	env = env;
	return (ret);
}

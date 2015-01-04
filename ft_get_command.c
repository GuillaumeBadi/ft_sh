/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:26:24 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 05:36:14 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		ft_is_executable(char *path)
{
	return (access(ft_strsplit(path, ' ')[0], X_OK) == 0);
}

int		ft_get_command(char *command, char ***env, t_alias **alias, t_list **history)
{
	int			ret;
	char		*bin;
	char		**set;
	char		*tr;
	char		**path;

	ret = 0;
	path = ft_get_path(*env);
	command = ft_strtrim(ft_fuckit(command));
	if (ft_strchr(command, ';') != NULL && !ft_strnequ(command, "alias", 5))
	{
		set = ft_strsplit(ft_strtrim(ft_fuckit(command)), ';');
		ret = exec_commands(env, alias, set, history);
		free(set);
		return (ret);
	}
//	if (ft_strlen(command) == 0)
//		return (0);
	if (!ft_strnequ(command, "alias", 5))
		*history = write_history(command, history);
	tr = translate_alias(alias, command);
	if (!ft_strequ(tr, command))
		ret = ft_get_command(tr, env, alias, history);
	else if (ft_strlen(ft_strtrim(tr)) == 0)
		ret = 0;
	else if (ft_strnequ(tr, "exit", 4))
		exit(0);
	else if (ft_strnequ(tr, "pwd", 3))
		ft_putendl(ft_pwd());
	else if (ft_strnequ(tr, "env", 3))
		ft_env(*env);
	else if (ft_strnequ(tr, "clear", 5))
		ft_clear();
	else if (ft_strnequ(tr, "alias", 5))
		*alias = ft_add_alias(tr + 6, alias);
	else if (ft_strnequ(tr, "cd", 2))
	{
	//	if (ft_strlen(ft_strtrim(tr)) > 2)
			ret = ft_cd(*env, path, tr + 2);
	//	else
	//		ret = ft_cd(*env, path, NULL);
	}
	else if (ft_strnequ(tr, "export", 6))
	{
		if (ft_strlen(ft_strtrim(tr)) > 6)
			ret = ft_setenv(env, ft_strtrim(tr + 6));
		else
			ret = -1;
	}
	else if (ft_strnequ(tr, "unset", 5))
		ret = ft_unsetenv(env, tr + 5);
		//ret = ft_unsetenv(env, ft_strtrim(command + 5));

	else if ((bin = ft_get_bin(tr, path)) != NULL)
	{
		ret = ft_exec(bin, tr, *env);
	}
	else if (ft_is_executable(tr))
	{
		ret = ft_exec(ft_strsplit(tr, ' ')[0], tr, *env);
	}
	else if (ft_strcmp(ft_strtrim(tr), ""))
	{
		ft_putendl(ft_strjoin("Minishell One: command not found: ", tr));
		ret = -1;
	}
	// Norme interruption
	path = path;
	env = env;
	return (ret);
}

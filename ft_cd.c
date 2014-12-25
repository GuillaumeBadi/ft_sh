/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:51:52 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 10:46:38 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int					get_error_cd(char *dir)
{
	struct stat			st;

	if (lstat(dir, &st) == 0 && !S_ISDIR(st.st_mode))
		ft_putendl(ft_strjoin("cd: not a directory: ", dir));
	else if (!S_ISREG(st.st_mode))
		ft_putendl(ft_strjoin("cd: No such file or directory: ", dir));
	else
		ft_putendl("permission denied");
	return (-1);
}

int					ft_cd(char **env, char **path, char *dir)
{
	char			*pwd;
	int				i;

	if (dir[0] == '~')
		dir = ft_strjoin(ft_get_home(env), dir + 1);
	if (chdir(dir) != 0)
		return (get_error_cd(dir));
	pwd = ft_pwd();
	i = ft_get_env(env, "PWD");
	env[i] = ft_strjoin("PWD=", pwd);
	(void)env;
	(void)path;
	(void)dir;
	return (0);
}

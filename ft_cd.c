/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:51:52 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/08 19:05:56 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int					get_error_cd(char *dir)
{
	struct stat			st;

	if (lstat(dir, &st) == 0 && !S_ISDIR(st.st_mode))
		ft_putendl(ft_strjoin("cd: Not a directory: ", dir));
	else if (!S_ISREG(st.st_mode))
		ft_putendl(ft_strjoin("cd: No such file or directory: ", dir));
	else
		ft_putendl("Permission denied");
	return (42);
}

int					ft_cd(char **env, char *dir)
{
	char			*pwd;
	int				i;

	if (!dir)
		dir = ft_get_home(env);
	dir = ft_split_custom(dir)[0];
	if (dir[0] == '~')
		dir = ft_strjoin(ft_get_home(env), dir + 1);
	if (dir[0] == '-' && !dir[1])
	{
		dir = env[ft_get_env(env, "OLDPWD")] + 7;
		ft_putendl(dir);
	}
	if (ft_strnequ(dir, "--", 2))
		dir = ft_strjoin(ft_get_home(env), dir + 2);
	i = ft_get_env(env, "OLDPWD");
	env[i] = ft_strjoin("OLDPWD=", ft_pwd());
	if (chdir(dir) != 0)
		return (get_error_cd(dir));
	pwd = ft_pwd();
	i = ft_get_env(env, "PWD");
	env[i] = ft_strjoin("PWD=", pwd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:32:42 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 22:45:08 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				main(int ac, char **av, char **env)
{
	char		**path;
	t_alias		*alias;

	alias = new_alias("shell", "echo Minishell One by GBadi");
	if (!env[0])
	{
		env = (char **)malloc(sizeof(char *) * 1);
		env[0] = 0;
		path = ft_strsplit("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin", ':');
	}
	else
	{
		path = ft_get_path(env);
	}
	ft_setenv(&env, ft_strjoin("PWD=", ft_pwd()));
	ft_setenv(&env, "USER=gbadi");
	ft_setenv(&env, ft_strjoin("OLDPWD=", ft_pwd()));
	ft_repl(env, path, &alias);
	(void)ac;
	(void)av;
	return (0);
}

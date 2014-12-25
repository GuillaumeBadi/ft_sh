/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:51:52 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 06:11:09 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fT_minishell1.h"

int					ft_cd(char **env, char **path, char *dir)
{
	char			*pwd;
	int				i;

	chdir(dir);
	pwd = ft_pwd(path, env);
	i = ft_get_env(env, "PWD");
	env[i] = ft_strjoin("PWD=", pwd);
	(void)env;
	(void)path;
	(void)dir;
	return (0);
}

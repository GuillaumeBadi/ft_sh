/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:32:42 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/28 00:11:17 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				main(int ac, char **av, char **env)
{
	char		**path;

	ft_setenv(&env, ft_strjoin("PWD=", ft_pwd()));
	ft_setenv(&env, ft_strjoin("OLDPWD=", ft_pwd()));
	path = ft_get_path(env);
	ft_repl(env, path);
	(void)ac;
	return (0);
}

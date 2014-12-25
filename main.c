/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:32:42 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 08:04:34 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				main(int ac, char **av, char **env)
{
	char		**path;

	path = ft_get_path(env);
	ft_repl(env, path);

	(void)ac;
	(void)av;
	(void)env;
	(void)path;
	return (0);
}

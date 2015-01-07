/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:50:19 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 01:05:14 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				**ft_get_path(char **env)
{
	int				i;
	char			**path;

	i = 0;
	while (!ft_strnequ(env[i], "PATH", 4))
		i++;
	path = ft_strsplit(&env[i][5], ':');
	return (path);
}

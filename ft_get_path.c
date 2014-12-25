/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:50:19 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 04:11:49 by gbadi            ###   ########.fr       */
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
	path = ft_strsplit(env[i], ':');
	return (path);
}

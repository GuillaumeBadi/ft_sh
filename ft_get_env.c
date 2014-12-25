/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 05:58:03 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 09:24:19 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				ft_get_env(char **env, char *name)
{
	int			i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], name, ft_strlen(name)))
			return (i);
		i++;
	}
	return (-1);
}

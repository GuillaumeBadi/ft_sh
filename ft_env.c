/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:18:58 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 05:14:42 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void				ft_env(char **env)
{
	int				i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

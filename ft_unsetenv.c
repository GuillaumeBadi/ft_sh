/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 07:57:38 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 09:04:30 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int					size_env(char **env)
{
	int				i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int					ft_unsetenv(char ***env, char *unset)
{
	char			**e;
	int				i;
	char			**new;
	int				j;

	j = 0;
	i = 0;
	e = *env;
	new = (char **)malloc(sizeof(char *) * size_env(e));
	while (e[i])
	{
		if (ft_strequ(ft_subc(e[i], '='), unset))
			i++;
		new[j] = ft_strdup(e[i]);
		i++;
		j++;
	}
	new[j] = 0;
	*env = new;
	return (0);
}

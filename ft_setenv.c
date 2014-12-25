/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 06:22:34 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 06:37:31 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int			create_env(char **env, char *xport, int len)
{
	char			**new;
	int				i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * len + 1);
	if (!new)
		return (-1);
	len++;
	while (i < len)
	{
		new[i] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	new[i] = ft_strdup(xport);
	free(env);
	env = new;
	return (1);
}

int					ft_setenv(char **env, char *xport)
{
	int				i;
	int				len;
	char			*name;

	i = 0;
	len = 0;
	while (xport[len + 1] != '=' && xport[len + 1] != '\0')
		len++;
	if (xport[len + 1] != '=')
		return (-1);
	name = ft_strndup(xport, len);
	while (env[i])
	{
		if (ft_strequ(env[i], name))
		{
			free(env[i]);
			env[i] = ft_strdup(xport);
			return (1);
		}
		i++;
	}
	return (create_env(env, xport, i));
}

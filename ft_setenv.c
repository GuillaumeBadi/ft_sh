/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 06:22:34 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 07:55:09 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char			**create_env(char **env, char *xport, int len)
{
	char			**new;
	int				i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * len + 2);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = ft_strdup(xport);
	new[i + 1] = 0;
	return (new);
}

char				*ft_subc(char *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (ft_strndup(s, i - 1));
	return (NULL);
}

char				**ft_setenv(char **env, char *xport)
{
	int				i;
	int				len;
	char			*name;

	i = 0;
	len = 0;
	while (xport[len + 1] != '=' && xport[len + 1] != '\0')
		len++;
	if (xport[len + 1] != '=')
		return (env);
	name = ft_strndup(xport, len);
	while (env[i])
	{
		if (ft_strequ(ft_subc(env[i], '='), name))
		{
			env[i] = ft_strdup(xport);
			return (env);
		}
		i++;
	}
	env = create_env(env, xport, i);
	return (env);
}

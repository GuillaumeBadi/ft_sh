/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 07:57:38 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:18:55 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int			get_len(char **e)
{
	int				i;

	i = 0;
	while (e[i])
		i++;
	return (i);
}

int					ft_unsetenv(char ***env, char *unset)
{
	char			**new;
	int				i;
	int				j;
	int				len;

	i = 0;
	j = 0;
	len = get_len(*env);
	new = (char **)malloc(sizeof(char *) * len);
	unset = ft_strtrim(unset);
	if (ft_strlen(unset) < 1 || ft_isonlyspace(unset))
	{
		ft_putendl("unset: Not enough arguments");
		return (-1);
	}
	while (i < len)
	{
		if (!ft_strnequ((*env)[i], unset, ft_strlen(unset)))
			new[j++] = ft_strdup((*env)[i]);
		i++;
	}
	new[j] = NULL;
	*env = new;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuckit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 20:42:31 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/27 19:11:13 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				*ft_fuckit(char *s)
{
	char			*new;
	int				i;
	int				j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[i])
	{
		if(ft_isspace(s[i]) && new[j - 1] != ' ')
		{
			new[j] = ' ';
			i++;
			j++;
		}
		else if (ft_isspace(s[i]))
			i++;
		else
		{
			new[j] = s[i];
			i++;
			j++;
		}
	}
	new[j] = '\0';
	return (new);
}

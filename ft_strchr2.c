/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 22:23:32 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:21:14 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				ft_strchr2(char const *s, int c)
{
	int			i;
	int			inside;

	i = 0;
	inside = 0;
	while (s[i])
	{
		if (s[i] == '\"' && inside == 0)
			inside = 1;
		else if (s[i] == '\"' && inside == 1)
			inside = 0;
		if (s[i] == c && inside == 0)
			return (1);
		i++;
	}
	return (0);
}

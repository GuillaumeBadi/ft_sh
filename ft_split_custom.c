/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 18:00:50 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 18:32:43 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char					**ft_split_custom(char *str)
{
	char				**tab;
	int					i;

	i = 0;
	tab = ft_strsplit(str, '\"');
	while (tab[i])
	{
		tab[i] = ft_strtrim(tab[i]);
		i++;
	}
	return (tab);
}

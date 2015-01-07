/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_alias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 05:36:44 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:37:08 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char					*translate_alias(t_alias **alias, char *command)
{
	char				**tab;
	char				*output;
	int					i;

	i = 0;
	tab = ft_strsplit(command, ' ');
	if (ft_strequ(tab[0], "alias"))
	{
		return (command);
	}
	output = get_output(*alias, tab[i]);
	if (output != NULL)
		tab[i] = ft_strdup(output);
	return (ft_tabjoin(tab));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 05:42:57 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 06:33:35 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int					is_valid(char *cmd)
{
	if (ft_strchr(cmd, '=') != NULL && ft_strlen(cmd) > 3)
		return (1);
	return (0);
}

t_alias				*ft_add_alias(char *command, t_alias **alias)
{
	char			*input;
	char			*output;

	if (ft_strlen(command) == 0)
		print_alias(*alias);
	else if (is_valid(command))
	{
		input = ft_subc(command, '=');
		output = ft_strdup(ft_strchr(command, '=') + 1);
		*alias = push_alias(*alias, input, output);
	}
	return (*alias);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:31:06 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 05:15:04 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void				ft_repl(char **env, char **path)
{
	char			*cmd;

	while (1)
	{
		cmd = ft_prompt();
		ft_get_command(cmd, path, env);
	}
	// Norme interruption
	cmd = cmd;
}

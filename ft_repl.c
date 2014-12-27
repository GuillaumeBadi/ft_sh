/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:31:06 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/26 03:04:58 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void				ft_repl(char **env, char **path)
{
	char			*cmd;
	int				ret;

	ret = 0;
	while (1)
	{
		cmd = ft_prompt(env, ret);
		if (cmd)
			ret = ft_get_command(cmd, path, &env);
	}
	cmd = cmd;
}

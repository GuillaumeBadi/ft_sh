/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:31:06 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 19:20:16 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void				ft_repl(char **env, char **path, t_alias **alias)
{
	char			*cmd;
	int				ret;

	ret = 0;
	signal(SIGINT, ft_exit);
	signal (SIGQUIT, ft_exit);
	ft_minishellrc(alias, path, &env);
	while (1)
	{
		cmd = ft_prompt(env, ret);
		if (cmd)
		{
			ret = ft_get_command(cmd, path, &env, alias);
		}
	}
	cmd = cmd;
}

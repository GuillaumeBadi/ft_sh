/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:31:06 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 23:15:08 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			exec_commands(char ***env, char **path, t_alias **alias, char **set)
{
	int				ret;
	int				i;
	char			*cmd;

	ret = 0;
	while (set[i])
	{
		cmd = ft_split_custom(set[i])[0];
		ret = ft_get_command(cmd, path, env, alias);
		i++;
	}
	return (ret);
}

void			ft_repl(char **env, char **path, t_alias **alias)
{
	char			*cmd;
	int				ret;

	ret = 0;
//	signal(SIGINT, ft_exit);
//	signal (SIGQUIT, ft_exit);
	ft_minishellrc(alias, path, &env);
	ft_putchar('\n');
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

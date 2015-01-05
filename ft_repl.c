/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:31:06 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 07:26:50 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			exec_commands(char ***env, t_alias **alias, char **set, t_list **history)
{
	int				ret;
	int				i;
	char			*cmd;

	ret = 0;
	while (set[i])
	{
		cmd = ft_split_custom(set[i])[0];
		ret = ft_get_command(cmd, env, alias, history);
		i++;
	}
	return (ret);
}

void			ft_repl(char **env, t_alias **alias, t_list **history)
{
	char			*cmd;
	int				ret;

	ret = 0;
	signal(SIGINT, ft_exit);
	ft_minishellrc(alias, &env, history);
	while (1)
	{
		cmd = ft_prompt(env, ret, history);
		if (cmd && ft_strlen(ft_strtrim(ft_fuckit(cmd))) > 0)
		{
			ret = ft_get_command(cmd, &env, alias, history);
		}
	}
	cmd = cmd;
}

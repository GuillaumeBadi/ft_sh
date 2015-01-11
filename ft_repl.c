/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:31:06 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/10 18:53:51 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		exec_commands(char ***e, t_alias **alias, char *set, t_list **history)
{
	int				ret;
	int				i;
	char			*cmd;
	char			**tab;

	ret = 0;
	i = 0;
	tab = ft_strsplit(set, ';');
	while (tab[i])
	{
		cmd = ft_split_custom(tab[i])[0];
		ret = ft_get_command(cmd, e, alias, history);
		i++;
	}
	free(tab);
	return (ret);
}

void	ft_repl(char **env, t_alias **alias, t_list **history)
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
			ret = ft_get_command(cmd, &env, alias, history);
	}
}

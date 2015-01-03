/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishellrc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 06:05:00 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 06:42:38 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void					ft_minishellrc(t_alias **alias, char **path, char ***env)
{
	char				*cmd;
	int					fd;
	int					line;
	int					ret;

	line = 0;
	fd = open("minishell1rc", O_RDONLY);
	while (get_next_line(fd, &cmd) > 0)
	{
		ret = ft_get_command(cmd, path, env, alias);
		line++;
		if (ret != 0)
			dprintf(1, "Minishell One: error line %d of minishellrc\n", line);
	}
}

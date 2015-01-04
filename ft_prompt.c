/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:24:14 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 05:27:17 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char				*get_dirname(char **env)
{
	char				*path;
	int					len;

	path = ft_pwd();
	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	if (env != NULL && ft_strequ(env[ft_get_env(env, "USER")] + 5, path + len + 1))
		return ("~");
	else if (!path[len - 1])
		return (path + len);
	return (path + len + 1);
}

void					ft_print_prompt(int r, char **env)
{
	// Norme interruption
	dprintf(1, "\033[2K\r");
	(r == 0) ? ft_putstr(COLOR_GREEN) : ft_putstr(COLOR_RED);
	ft_putstr("➜  ");
	ft_putstr(COLOR_RESET);
	ft_putstr(COLOR_CYAN);
	ft_putstr(get_dirname(env));
	ft_putstr(COLOR_RESET);
	ft_putchar(' ');
}

char					*ft_prompt(char **env, int r, t_list **history)
{
	char				*s;

	s = gnl(0, env, r, history);
	if (!ft_strtrim(s))
		return (NULL);
	return (s);
}

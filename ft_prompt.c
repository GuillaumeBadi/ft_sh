/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:24:14 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 01:08:12 by gbadi            ###   ########.fr       */
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
	if (ft_strequ(env[ft_get_env(env, "USER")] + 5, path + len + 1))
		return ("~");
	else if (!path[len - 1])
		return (path + len);
	return (path + len + 1);
}

void					ft_print_prompt(int r, char **env)
{
	(r == 0) ? ft_putstr(COLOR_GREEN) : ft_putstr(COLOR_RED);
	ft_putstr("➜  ");
	ft_putstr(COLOR_RESET);
	ft_putstr(COLOR_CYAN);
	ft_putstr(get_dirname(env));
	ft_putstr(COLOR_RESET);
	ft_putchar(' ');
}

char					*ft_prompt(char **env, int r)
{
	char				*s;
	int					ret;

	ft_print_prompt(r, env);
	//ret = get_next_line(0, &s);
	ret = gnl(&s, 0, env, r);
	if (!ft_strtrim(s))
		return (NULL);
	if (ret == -1)
		return (NULL);
	return (s);
}

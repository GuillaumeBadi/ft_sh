/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:24:14 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 09:10:32 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char				*get_dirname()
{
	char				*path;
	int					len;

	path = ft_pwd();
	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	if (!path[len - 1])
		return (path + len);
	return (path + len + 1);
}

char					*ft_prompt(void)
{
	char				*s;
	int					ret;

	s = NULL;
	ft_putstr(COLOR_GREEN);
	ft_putstr("➜  ");
	ft_putstr(COLOR_RESET);
	ft_putstr(COLOR_CYAN);
	ft_putstr(get_dirname());
	ft_putstr(COLOR_RESET);
	ft_putchar(' ');
	ret = get_next_line(0, &s);
	if (ret == -1)
		return (NULL);
	return (s);
}

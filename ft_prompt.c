/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:24:14 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 04:38:07 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char					*ft_prompt(void)
{
	char				*s;
	int					ret;

	s = NULL;
	ft_putstr(COLOR_GREEN);
	ft_putstr("➜  ");
	ft_putstr(COLOR_RESET);
	ret = get_next_line(0, &s);
	if (ret == -1)
		return (NULL);
	return (s);
}

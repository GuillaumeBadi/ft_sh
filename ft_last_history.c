/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:10:47 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:31:14 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				*ft_last_history(void)
{
	char			*s;
	int				fd;

	s = NULL;
	fd = open("minishell-history", O_RDONLY);
	while (get_next_line(fd, &s) > 0)
		;
	return (s);
}

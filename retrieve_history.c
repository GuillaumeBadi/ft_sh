/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 05:30:09 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:30:27 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				*retrieve_history(t_list *list, int direction)
{
	static int		offset;
	int				len;
	char			*res;

	len = list_len(list);
	res = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (direction == 0)
	{
		offset = 0;
		return (0);
	}
	if (direction == UP)
		offset--;
	if (direction == DOWN)
		offset++;
	if (offset > len)
		offset = 0;
	if (len + offset < 0)
		offset = -len;
	if (len + offset >= len)
		return (res);
	res = get_index(list, len + offset);
	return (res);
}

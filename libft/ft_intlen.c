/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:10:32 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/14 05:54:25 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_intlen(int number)
{
	int			i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = -number;
		i = 1;
	}
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:09:59 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/24 16:10:24 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_atoi(const char *str)
{
	int			result;
	int			i;
	int			sign;

	result = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - 48;
	return (result * sign);
}

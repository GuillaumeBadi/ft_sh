/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:10:25 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:10:27 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_iformat(char *str, int number)
{
	char		*dest;
	char		*current;

	dest = (char *)malloc(sizeof(char) * ft_intlen(number) + ft_strlen(str));
	current = dest;
	while (*str)
	{
		if (*str == '^')
		{
			current = ft_strcat(current, ft_itoa(number));
			current += ft_intlen(number);
		}
		else
		{
			*current = *str;
			current += 1;
		}
		str++;
	}
	return (dest);
}

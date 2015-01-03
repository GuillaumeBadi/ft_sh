/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:06:19 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/24 16:11:17 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strtoupper(char *str)
{
	char			*s;
	int				i;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		s[i] = ft_toupper(str[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}

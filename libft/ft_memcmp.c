/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:13:35 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:13:36 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	if (*ss1 == *ss2 && n == 1)
		return (0);
	else if (*ss1 == *ss2)
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	return (*ss1 - *ss2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:22:34 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/31 14:22:42 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strnstr(char const *s1, const char *s2, size_t n)
{
	char		*tmp_s1;
	size_t		i;
	size_t		j;
	int			len_s2;

	i = 0;
	tmp_s1 = (char *)s1;
	len_s2 = ft_strlen(s2);
	if (!len_s2)
		return ((char *)s1);
	while (tmp_s1[i] && i < n)
	{
		if (tmp_s1[i] == s2[0])
		{
			j = 0;
			while (tmp_s1[i + j] == s2[j] && (i + j) < n)
				j++;
			if (!s2[j])
				return (&tmp_s1[i]);
		}
		i++;
	}
	return (NULL);
}

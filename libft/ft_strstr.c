/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:43 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:18:44 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	char		*s;

	s = (char *)s1;
	while (*s++)
		if (ft_strnequ(s, s2, ft_strlen(s2)))
			return (s);
	return (NULL);
}

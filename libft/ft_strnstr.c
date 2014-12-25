/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:30 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:18:31 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char			*ft_strnstr(char const *s1, const char *s2, size_t len)
{
	char		*new_s2;

	new_s2 = (char *)malloc(sizeof(char) * len);
	new_s2 = ft_strncpy(new_s2, (char *)s2, len);
	return (ft_strstr(s1, new_s2));
}

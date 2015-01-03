/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:41:12 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 01:11:16 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strtrim(char const *s)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) && i <= len)
		i++;
	while (ft_isspace(s[len]) && len > 0)
		len--;
	return (ft_strsub(s, i, len - i + 1));
}

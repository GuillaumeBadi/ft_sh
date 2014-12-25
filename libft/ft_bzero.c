/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:10:14 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:10:15 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_bzero(void *s, size_t n)
{
	s = ft_memset(s, 0, n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:12:21 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:12:21 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_lstdel_next(t_list *alst, void (*del)(void *, size_t len))
{
	if (!alst)
		return ;
	else
	{
		ft_lstdel_next(alst->next, del);
		ft_lstdelone(&alst, del);
	}
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t len))
{
	ft_lstdel_next(*alst, del);
	*alst = NULL;
}

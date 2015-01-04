/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:13:28 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 05:30:45 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void					ft_exit(int s)
{
	s = s;
	signal(SIGINT, ft_exit);
	// Norme interruption
	ft_putendl("");
	ft_print_prompt(1, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:09:22 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/27 19:05:28 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	ft_wordcount(char *s, char c)
{
	int		wc;
	char	p;

	wc = 0;
	p = 0;
	while (*s)
	{
		if (*s != c && !p)
		{
			p = 1;
			wc++;
		}
		if (*s++ == c)
			p = 0;
	}
	return (wc);
}

static int	ft_filltab(char *s, char c, char **tab)
{
	int		w;
	int		lc;

	w = 0;
	lc = 0;
	while (*s)
	{
		if (*s != c)
			lc++;
		if (*s++ == c && lc)
		{
			tab[w] = (char *)malloc(sizeof(char) * (lc + 1));
			if (!tab[w++])
				return (0);
			lc = 0;
		}
	}
	if (lc)
	{
		tab[w] = (char *)malloc(sizeof(char) * (lc + 1));
		if (!tab[w++])
			return (0);
	}
	tab[w] = NULL;
	return (1);
}

static void	ft_fillstrings(char *s, char c, char **tab)
{
	int		w;
	int		lc;
	int		i;

	lc = 0;
	w = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tab[w][i++] = *s;
			lc++;
		}
		if (*s++ == c && lc)
		{
			lc = 0;
			tab[w][i] = '\0';
			w++;
			i = 0;
		}
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
	{
		tab = (char **)malloc(sizeof(char *) * 1);
		tab[0] = NULL;
		return (tab);
	}
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	if (!ft_filltab((char *)s, c, tab))
		return (NULL);
	ft_fillstrings((char *)s, c, tab);
	return (tab);
}

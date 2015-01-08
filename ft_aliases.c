/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aliases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:26:10 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 20:39:13 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_alias					*new_alias(char *input, char *output)
{
	t_alias				*new;

	new = (t_alias *)malloc(sizeof(t_alias));
	new->input = ft_strdup(input);
	new->output = ft_strdup(output);
	new->next = NULL;
	return (new);
}

t_alias					*push_alias(t_alias *alias, char *input, char *output)
{
	t_alias				*new;
	t_alias				*current;

	new = new_alias(input, output);
	current = alias;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (alias);
}

char					*get_output(t_alias *alias, char *input)
{
	t_alias				*current;

	current = alias;
	while (current != NULL)
	{
		if (ft_strequ(current->input, input))
		{
			return (current->output);
		}
		current = current->next;
	}
	return (NULL);
}

char					*ft_tabjoin(char **tab)
{
	int					i;
	char				*new;

	i = 0;
	new = "";
	while (tab[i])
	{
		new = ft_strjoin(ft_strjoin(new, (i == 0) ? "" : " "), tab[i]);
		i++;
	}
	return (new);
}

void					print_alias(t_alias *alias)
{
	t_alias				*current;

	current = alias;
	while (current != NULL)
	{
		ft_putstr(current->input);
		ft_putstr("\t\t=> output: ");
		ft_putendl(current->output);
		current = current->next;
	}
}

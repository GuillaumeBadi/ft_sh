/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aliases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:26:10 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 22:44:18 by gbadi            ###   ########.fr       */
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
		ft_putstr("input: ");
		ft_putstr(current->input);
		ft_putstr(" => output: ");
		ft_putendl(current->output);
		current = current->next;
	}
}

char					*translate_alias(t_alias **alias, char *command)
{
	char				**tab;
	char				*output;
	int					found;
	int					i;

//	print_alias(*alias);
	found = 0;
	i = 0;
	tab = ft_strsplit(command, ' ');
	if (ft_strequ(tab[0], "alias"))
	{
		return (command);
	}
	output = get_output(*alias, tab[i]);
	if (output != NULL)
	{
		tab[i] = ft_strdup(output);
		found = 1;
	}
	return (found ? translate_alias(alias, ft_tabjoin(tab)) : ft_tabjoin(tab));
}


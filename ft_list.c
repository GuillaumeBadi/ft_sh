/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 02:32:53 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:30:30 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_list				*new_list(void)
{
	t_list			*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->entry = "";
	list->next = NULL;
	return (list);
}

t_list				*push_list(t_list *list, char *entry)
{
	t_list			*current;
	t_list			*new;

	current = list;
	new = new_list();
	new->entry = ft_strdup(entry);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (list);
}

char				*get_index(t_list *list, int index)
{
	int				i;
	t_list			*current;

	i = 0;
	current = list;
	while (current != NULL)
	{
		if (i == index)
		{
			return (current->entry);
		}
		current = current->next;
		i++;
	}
	return (0);
}

t_list				*write_history(char *cmd, t_list **list)
{
	ft_putline("minishell-history", cmd);
	*list = push_list(*list, cmd);
	return (*list);
}

int					list_len(t_list *list)
{
	int				i;
	t_list			*current;

	i = 0;
	current = list;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

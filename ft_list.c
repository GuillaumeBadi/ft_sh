/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 02:32:53 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 07:48:43 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void				print_list(t_list *list)
{
	t_list			*current;

	current = list;
	dprintf(1, "\n");
	while (current != NULL)
	{
		// Norme interruption
		dprintf(1, "%s\n", current->entry);
		current = current->next;
	}
}

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

char				*retrieve_history(t_list *list, int direction)
{
	static int		offset;
	int				len;
	char			*res;

	len = list_len(list);
	res = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (direction == 0)
	{
		offset = 0;
		return (0);
	}
	if (direction == UP)
		offset--;
	if (direction == DOWN)
		offset++;
	if (offset > len)
		offset = 0;
	if (len + offset < 0)
		offset = -len;
	if (len + offset >= len)
		return (res);
	res = get_index(list, len + offset);
	return (res);
}

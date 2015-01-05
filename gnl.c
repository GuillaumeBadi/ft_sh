/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 00:42:33 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 08:41:29 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char			*gnl(int fd, char **env, int ret, t_list **history)
{
	char		*dest;
	int			c;
	int			i;

	i = 0;
	ft_print_prompt(ret, env);
	dest = malloc(sizeof(char) * BUFF_SIZE);
	while ((c = ft_getc(fd)) != 0 && c != '\n' && i < BUFF_SIZE - 1)
	{
//		dprintf(1, "%c", c);
		//// Norme interruption
		//dprintf(1, "%d\n", c);
		if (c == 4)
		{
			exit(0);
		}
		else if (c == '\033')
		{
			ft_getc(fd);
			c = ft_getc(fd);
			if (c == 'A')
			{
				// Norme interruption
				dprintf(1, "\033[2K\r");
				dest = retrieve_history(*history, UP);
				i = ft_strlen(dest);
				ft_print_prompt(ret, env);
				ft_putstr(dest);
			}
			else if (c == 'B')
			{
				dprintf(1, "\033[2K\r");
				dest = retrieve_history(*history, DOWN);
				i = ft_strlen(dest);
				ft_print_prompt(ret, env);
				ft_putstr(dest);
			}
			else if (c == 'C')
			{
				//right
			}
			else if (c == 'D')
			{
				//left
			}
		}
		else if (c == 127)
		{
			dprintf(1, "\033[2K\r");
			ft_print_prompt(ret, env);
			if (ft_strlen(dest) > 0)
			{
				dest[i - 1] = '\0';
				i--;
				ft_putstr(dest);
			}
		}
		else if (c == 3)
		{
			//inutile a cause de signal.h
			ft_exit(ret);
			free(dest);
			dest = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
			i = 0;
			ret = 1;
		}
		else if (c == 12)
		{
			ft_clear();
			ft_print_prompt(ret, env);
			dprintf(1, "%s", dest);
		}
		else
		{
			// Norme interruption
			dprintf(1, "%c", c);
			dest[i] = c;
			dest[i + 1] = '\0';
			i++;
		}
	}
	// Norme interruption
	dprintf(1, "\n");
	retrieve_history(*history, 0);
	return (ft_strdup(dest));
}

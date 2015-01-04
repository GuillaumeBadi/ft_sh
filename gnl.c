/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 00:42:33 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 01:25:30 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			gnl(char **sp, int fd, char **env, int ret)
{
	char		*dest;
	char		*buffer;
	//char		*end;
	int			c;
	int			i;

	dest = malloc(sizeof(char) * BUFF_SIZE);
	buffer = dest;
	//end = buffer + BUFF_SIZE - 1;
	while ((c = ft_getc(fd)) != 0 && c != '\n' && i < BUFF_SIZE - 1)
	{
		if (c == 12)
		{
			ft_clear();
			ft_print_prompt(ret, env);
			dprintf(1, "%s", buffer);
		}
		else
		{
			// Norme interruption
			dprintf(1, "%c", c);
			buffer[i] = c;
			i++;
		}
	}
	// Norme interruption
	dprintf(1, "\n");
	buffer[i] = '\0';
	*sp = ft_strdup(dest);
	return ((c == 0 && ft_strlen(buffer) == 0) ? 0 : 1);
}

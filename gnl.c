/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 00:42:33 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 06:03:30 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

#define FUCK {ft_putchar(c); dest[i] = c; i++;}

int				get_up_key(char **dest, char **env, int ret, t_list **history)
{
	ft_putstr("\033[2K\r");
	*dest = retrieve_history(*history, UP);
	ft_print_prompt(ret, env);
	ft_putstr(*dest);
	return (ft_strlen(*dest));
}

int				get_down_key(char **dest, char **env, int ret, t_list **history)
{
	ft_putstr("\033[2K\r");
	*dest = retrieve_history(*history, DOWN);
	ft_print_prompt(ret, env);
	ft_putstr(*dest);
	return (ft_strlen(*dest));
}

int				backspace(char **env, int ret, int i, char **dest)
{
	ft_putstr("\033[2K\r");
	ft_print_prompt(ret, env);
	if (ft_strlen(*dest) > 0)
	{
		(*dest)[i - 1] = '\0';
		i -= 1;
		ft_putstr(*dest);
	}
	return (i);
}

char			*clr(char *dest, char **env, int ret)
{
	ft_clear();
	ft_print_prompt(ret, env);
	ft_putstr(dest);
}

int				ft_key(int fd, char **env, int ret, t_list *list)
{
	char		c;
	int			i;

	ft_getc(fd);
	c = ft_getc(fd);
	i = 0;
	if (c == 'A')
		i = get_up_key(&dest, env, ret, history);
	else if (c == 'B')
		i = get_down_key(&dest, env, ret, history);
	return (i);
}

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
		if (c == 4)
			exit(0);
		else if (c == '\033')
			ft_key(fd, env, ret, list);
		else if (c == 127)
			i = backspace(env, ret, i, &dest);
		else if (c == 12)
			clr(dest, env, ret);
		else
			FUCK;
	}
	ft_putendl("");
	dest[i] = '\0';
	retrieve_history(*history, 0);
	return (ft_strdup(dest));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 23:14:47 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/10 18:59:55 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				**ft_append(char **bla, char *s)
{
	char			**new;
	int				i;
	int				len;
	int				j;

	i = 0;
	len = 0;
	j = 0;
	while (bla[len])
		len++;
	new = (char **)malloc(sizeof(char *) * len + 2);
	while (i < len + 1)
	{
		if (i == 1)
			new[i] = ft_strdup(s);
		else
		{
			new[i] = ft_strdup(bla[j]);
			j++;
		}
		i++;
	}
	new[i] = 0;
	return (new);
}

int					ft_exec(char *bin, char *command, char **env)
{
	pid_t			child;
	int				status;
	char			**bla;

	child = fork();
	if (child < 0)
		return (-1);
	if (child > 0)
		waitpid(child, &status, 0);
	else
	{
		bla = ft_strsplit_whitespace(command);
		if (ft_strequ(bla[0], "ls"))
			bla = ft_append(bla, "-G");
		if (execve(bin, bla, env) < 0)
			ft_putendl(ft_strjoin(bin, ": Unknown error"));
	}
	return (WEXITSTATUS(status));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 23:14:47 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/03 19:06:02 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int					ft_exec(char *bin, char *command, char **env)
{
	pid_t			child;
	int				status;
	char			**bla;

	child = fork();
	if (child < 0)
		return (-1);
	if (child > 0)
	{
		waitpid(child, &status, 0);
	}
	else
	{
		//bla = ft_strsplit(command, ' ');
		bla = ft_strchr(command, '\"') != NULL ? ft_split_custom(command) : ft_strsplit(command, ' ');
		if (execve(bin, bla, env) < 0)
		{
			// Norme interruption
			dprintf(1, "%s\n", "error");
		}
		exit(-1);
	}
	return (WEXITSTATUS(status));
}

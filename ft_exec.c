/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 23:14:47 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/26 21:28:27 by gbadi            ###   ########.fr       */
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
		bla = ft_strsplit(ft_fuckit(command), ' ');
		execve(bin, bla, env);
		exit(-1);
	}
	return (WEXITSTATUS(status));
}

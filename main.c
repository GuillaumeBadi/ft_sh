/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:32:42 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/04 00:45:09 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void				start_termios(void)
{
	struct termios	attributes;
	int				fd;

	fd = STDIN_FILENO;
	if (!isatty(fd))
		exit (1);
	if (tcdrain(fd) == -1 || tcgetattr(fd, &attributes) == -1)
		exit (-1);
	attributes.c_lflag &= ~ICANON;
	attributes.c_lflag &= ~ECHO;
	attributes.c_cc[VMIN] = 1;
	attributes.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSADRAIN, &attributes) == -1)
		exit(-1);
	return ;
}

int					main(int ac, char **av, char **env)
{
	char		**path;
	t_alias		*alias;

	start_termios();
	alias = new_alias("shell", "echo Minishell One by GBadi");
	if (!env[0])
	{
		env = (char **)malloc(sizeof(char *) * 1);
		env[0] = 0;
		path = ft_strsplit("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin", ':');
	}
	else
	{
		path = ft_get_path(env);
	}
	ft_setenv(&env, ft_strjoin("PWD=", ft_pwd()));
	ft_setenv(&env, "USER=gbadi");
	ft_setenv(&env, ft_strjoin("OLDPWD=", ft_pwd()));
	ft_repl(env, path, &alias);
	(void)ac;
	(void)av;
	return (0);
}

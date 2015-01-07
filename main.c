/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 03:32:42 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/07 05:17:46 by gbadi            ###   ########.fr       */
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
	attributes.c_lflag &= ~(ECHOK | ECHO | ECHONL | ECHOE | IEXTEN);
	attributes.c_cc[VMIN] = 1;
	attributes.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSADRAIN, &attributes) == -1)
		exit(-1);
	return ;
}

t_list				*get_history(void)
{
	t_list			*list;
	int				fd;
	char			*s;

	s = NULL;
	list = new_list();
	fd = open("minishell-history", O_RDONLY);
	while (get_next_line(fd, &s) > 0)
		list = push_list(list, s);
	close(fd);
	if (list->next)
		list = list->next;
	return (list);
}

int					main(int ac, char **av, char **env)
{
	t_alias		*alias;
	t_list		*history;
	char		*path1;
	char		*path2;

	path1 = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:";
	path2 = "/usr/texbin:/nfs/zfs-student-2/users/2014/gbadi/.brew/bin";
	history = get_history();
	start_termios();
	alias = new_alias("shell", "echo Minishell One by GBadi");
	if (!env[0])
	{
		env = (char **)malloc(sizeof(char *) * 1);
		env[0] = 0;
		ft_setenv(&env, ft_strjoin(path1, path2));
		ft_setenv(&env, "HOME=/nfs/zfs-student-2/users/2014/gbadi");
	}
	ft_setenv(&env, ft_strjoin("PWD=", ft_pwd()));
	ft_setenv(&env, "USER=gbadi");
	ft_setenv(&env, ft_strjoin("OLDPWD=", ft_pwd()));
	ft_repl(env, &alias, &history);
	(void)ac;
	(void)av;
	return (0);
}

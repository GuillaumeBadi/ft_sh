/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 22:38:19 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/08 18:44:08 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				*get_first_word(char *command)
{
	int				i;

	i = 0;
	while (command[i] && command[i] > ' ')
		i++;
	return (ft_strsub(command, 0, i));
}

int					dir_has(char *dir, char *command)
{
	DIR				*directory;
	struct dirent	*ret;

	directory = opendir(dir);
	if (directory == NULL)
		return (0);
	while ((ret = readdir(directory)) != NULL)
	{
		if (ft_strequ(ret->d_name, command))
			return (1);
	}
	return (0);
}

char				*ft_get_bin(char *command, char **path)
{
	int				i;
	char			*word;

	i = 0;
	word = get_first_word(command);
	while (path[i])
	{
		if (dir_has(path[i], word) && !ft_strequ(".", command))
			return (ft_strjoin(ft_strjoin(path[i], "/"), word));
		i++;
	}
	return (NULL);
}

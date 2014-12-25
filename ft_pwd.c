/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 04:54:19 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/25 06:09:02 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char				*ft_pwd(char **path, char **env)
{
	char			dir[1024];

	if (getcwd(dir, sizeof(dir)) != NULL)
		return (ft_strdup(dir));
	(void)path;
	(void)env;
	return (NULL);
}

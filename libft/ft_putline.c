/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:31:29 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/31 14:50:02 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

int				ft_putline(char *fname, char *line)
{
	int			fd;

	line = ft_strjoin(line, "\n");
	if (ft_strequ(fname, "stdout"))
		fd = 1;
	else if (ft_strequ(fname, "stderr"))
		fd = 2;
	else if ((fd = open(fname, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU |
					S_IRWXG | S_IROTH | S_IXOTH)) > 2 && line != NULL)
		write(fd, line, ft_strlen(line));
	else
		return (0);
	return (1);
}

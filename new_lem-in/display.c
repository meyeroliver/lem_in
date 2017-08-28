/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 07:47:14 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/28 08:25:39 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	errorr_display(int err_no)
{
	if (err_no == 1)
		ft_putendl("ERROR!\nThere are no ants to move.");
	if (err_no == 2)
		ft_putendl("ERROR!\nThere are no rooms to hold the ants.");
	if (err_no == 3)
		ft_putendl("ERROR!\nThere is no starting point for ants.");
	if (err_no == 4)
		ft_putendl("ERROR!\nThere are no end point for ant to go to.");
}

void	display_top(char *filename)
{
	int		fd;
	char	*line;

	fd = open_file(filename);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(ft_strchr(line, '-')))
			ft_putendl(line);
		free(line);
	}
	close_file(fd, filename);
}

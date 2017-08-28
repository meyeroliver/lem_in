/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handeling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:09:52 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/28 08:25:34 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(filename);
		ft_putstr(" does not exist. Please insert a valid filname\n");
	}
	return (fd);
}

void	close_file(int	fd, char *filename)
{
	if (close(fd) == -1)
	{
		ft_putstr(filename);
		ft_putstr(" did not close correctly\n");
	}
}

void		file_handling(char	*filename)
{
	t_node_r    *head;
	int			fd;
	int			handler;


	fd = open_file(filename);
	handler = break_up(fd, &head);
	if (handler == 0)
	{
		display_top(filename);
	}
	else
		errorr_display(handler);

	close_file(fd, filename);
}

int	break_up(int fd, t_node_r **head)
{
	t_check		check;
	char		*line;
		
	check.ants = 0;
	check.start = 0;
	check.end = 0;
	check.room = 0;
	while (get_next_line(fd, &line) > 0)
	{
		check =	checks(line, check, head);
		free(line);
	}
	return (err_handling(*head, check.ants, check.room));
}

int		main(int argc, char **argv)
{
	//this is a just for now check until 
	//i figure out how the redirection works
	if (argc - 1 == 0)
	{
		ft_putendl("When executing the program, please ensure to enter");
		ft_putendl("in a textfile e.g ./lem-in map.txt");
	}
	else if (argc - 1 > 1)
		ft_putendl("Too many arguments");
	else
		file_handling(argv[1]);
	return (0);
}

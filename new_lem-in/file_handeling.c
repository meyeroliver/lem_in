/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handeling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:09:52 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/19 15:56:41 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void			file_handling(char	*filename)
{
	int		fd;
	t_node_r    *head;
	t_graph     *graphs;
	t_node_g *path;
	t_node_a	*ants;
		
	path = NULL;
	graphs = NULL;
	ants = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(filename);
		ft_putstr(" does not exist. Please insert a valid filname\n");
	}
	if (break_up(fd, &head, &graphs, &ants) == 1)
	{
		ft_putendl("Call the other functions");
		path_finder(&graphs/*, head*/, &path);
		ft_putendl("PATH");
		print_list_g(path);
		print_list_a(ants);
	//	ft_putendl("moving the ants");
		move_ants(&ants, &path, graphs);
	}
	if (close(fd) == -1)
	{
		ft_putstr(filename);
		ft_putstr(" did not close correctly\n");
	}
}

static void	create_room(char *line, t_check *check, t_node_r **head)
{
	t_data_r    temp_data;
	char        **split;
	static int	n = 1;

	split = ft_strsplit(line, ' ');
	temp_data.room = ft_atoi(split[0]);
	temp_data.point.x = ft_atoi(split[1]);
	temp_data.point.y = ft_atoi(split[2]);
	if (check->start == 1)
	{
		temp_data.start = 1;
		check->start = 0;
	}
	else
		temp_data.start = 0;
	if (check->end == 1)
	{
		temp_data.end = 1;
		check->end = 0;
	}
	else
		temp_data.end = 0;
	push_back(temp_data, n, head);
	n++;
}

t_check		checks(char *line, t_check check, t_node_r **head)
{
	if (!(ft_strchr(line, '#')) && !(ft_strchr(line, '-')) &&
			(ft_strlen(line) != 1))
	{
		check.room++;
		create_room(line, &check, head);
	}
	if (ft_strlen(line) == 1)
		check.ants = ft_atoi(line);
	if (ft_strcmp(line, "##start") == 0)
		check.start = 1;
	if (ft_strcmp(line, "##end") == 0)
		check.end = 1;
	return (check);
}

void			create_ants(int ants, t_node_a **head, t_graph *graph)
{
	int			i;
	t_data_a	temp;

	i = 1;
	while (i <= ants)
	{
		temp.id = i;
		temp.index = find_start(graph).id;
		push_back_a(temp, i, head);
		i++;
	}
}

int	break_up(int fd, t_node_r **head, t_graph **graphs, t_node_a **head_a)
{
	t_check		check;
	char		*line;
	char        **split;
	int			i;

	check.ants = 0;
	check.start = 0;
	check.end = 0;
	check.room = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		check =	checks(line, check, head);
		if (ft_strchr(line, '-'))
		{
			if (i == 0)
			{
				*graphs = graph(check.room);
				i = 1;
			}
			split = ft_strsplit(line, '-');
		add_edge(*graphs, ft_atoi(split[0]), ft_atoi(split[1]), *head);
		}
		free(line);
	}
	create_ants(check.ants, head_a, *graphs);
	return((error_handling(*head, check.ants, check.room) == -1) ? -1 : 1);
}

int		error_handling(t_node_r *head, int ants, int rooms)
{
	t_node_r	*temp;
	int			start;
	int			end;

	start = 0;
	end = 0;
	if (ants == 0)
		ft_putendl("ERROR!\nThere are no ants to move.");
	if (rooms == 0)
		ft_putendl("ERROR!\nThere are no rooms to hold the ants.");
	temp = head;
	while (temp)
	{
		if (temp->data.start == 1)
			start = 1;
		if (temp->data.end == 1)
			end = 1;
		temp = temp->next;
	}
	if (start == 0)
		ft_putendl("ERROR!\nThere is no starting point for ants.");
	if (end == 0)
		ft_putendl("ERROR!\nThere are no end point for ant to go to.");
	return ((ants == 0 || rooms == 0 || start == 0 || end == 0) ? -1 : 1);
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

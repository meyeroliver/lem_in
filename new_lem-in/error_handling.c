/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 07:26:36 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/28 07:53:05 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_check     checks(char *line, t_check check, t_node_r **head)
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

//I dont wont a return function 

int     err_handling(t_node_r *head, int ants, int rooms)
{
	t_node_r    *temp;
	int         start;
	int         end;
	start = 0;
	end = 0;
	if (ants == 0)
		return (1);
	//	ft_putendl("ERROR!\nThere are no ants to move.");
	if (rooms == 0)
		return (2);
	//	ft_putendl("ERROR!\nThere are no rooms to hold the ants.");
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
		return (3);
//		ft_putendl("ERROR!\nThere is no starting point for ants.");
	if (end == 0)
		return (4);
	return (0);
	//	ft_putendl("ERROR!\nThere are no end point for ant to go to.");
//return ((ants == 0 || rooms == 0 || start == 0 || end == 0) ? -1 : 1);
}


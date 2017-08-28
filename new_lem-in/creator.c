/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 07:16:37 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/28 07:26:16 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_room(char *line, t_check *check, t_node_r **head)
{
	t_data_r    temp_data;
	char        **split;
	static int  n = 1;

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

/*
void	create_ants(int ants, t_node_a **head, t_graph *graph)
{
	int         i;
	t_data_a    temp;

	i = 1;
	while (i <= ants)
	{
		temp.id = i;
		temp.index = find_start(graph).id;
		push_back_a(temp, i, head);
		i++;
	}
}
*/

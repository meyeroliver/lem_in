/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:08:08 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/20 18:26:09 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static void	reset_path(t_node_g **path, t_graph *graph)
{
	t_node_g    *way;

	way = *path;
	while (way)
	{
		if (find_start(graph).id != way->data.id)
			way->data.visited = 0;
		way = way->next;
	}
}

void	move_ants(t_node_a **ants, t_node_g **path, t_graph *graph)
{
	t_node_g	*way;
	t_node_g	*ptr_w;
	t_node_a	*temp_ants;
	t_node_a	*ptr_a;
	int			i;

	i = 0;
	reset_path(path, graph);
	temp_ants = *ants;
	way = *path;
	ptr_a = temp_ants;
	printf("\n");
	while (i < 13/*colony_size(*ants)*/)
	{
		ptr_w = way;
		while (ptr_w->data.id != ptr_a->data.index)
			ptr_w = ptr_w->next;
		if (ptr_w->next->data.visited == 0)
		{
			ptr_a->data.index = ptr_w->next->data.id;
			ptr_w->next->data.visited = 1;
			ptr_w->data.visited = 0;
			printf("L%d-%d ", ptr_a->data.id, ptr_a->data.index);
		//	if (ptr_a->data.index == find_end(graph).data.id)
		//	{
		//		i++;
		//		printf(" awe %d ", pop_a(&temp_ants));
		//		ptr_a = temp_ants;
		//	}
			ptr_a = ptr_a->next;
		}
		else
		{
			ptr_a = temp_ants;
			printf("\n");
		}
		i++;
	}
}





































































/*	while (i <  colony_size(*ants))
	{
	while (way->next)
	{
	way = way->next;
	colony->data.index = way->data.id;
	printf("\nL%d-%d p-v%d", colony->data.id, colony->data.index, way->data.visited);
	}
	way = *path;
	colony = colony->next;
	i++;
	}
	*/
//}

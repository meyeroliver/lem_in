/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:30:53 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/19 14:45:04 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
/*
t_data_r      find_start(t_node_r *head)
{
	t_node_r *temp;
	t_data_r  start;

	temp = head;
	while (temp)
	{
		if(temp->data.room == 1)
		{
			start = temp->data;
		}
		temp = temp->next;
	}
	return (start);
}
*/
t_data_g    find_start(t_graph *graph)
{
	int         i;
	t_data_g    start;
	t_node_g    *trav;
	i = 0;
	while (i < graph->v)
	{
		trav = graph->array[i].head;
		while (trav != NULL)
		{
			if (trav->data.room.start == 1)
				start = trav->data;
			trav = trav->next;
		}
		i++;
	}
	return(start);
}

t_node_g	find_end(t_graph *graph)
{
	int			i;
	t_node_g	end;
	t_node_g	*trav;

	i = 0;
	while (i < graph->v)
	{
		trav = graph->array[i].head;
		while (trav != NULL)
		{
			if (trav->data.room.end == 1)
				end.data = trav->data;
			trav = trav->next;
		}
		i++;
	}
	return(end);
}

int     check_neighbour(t_graph *g, int ref, t_node_g  **n_door, int n)
{
	int     i;
	t_node_g  *trav;

	i = 0;
	while (i < g->v)
	{
		trav = g->array[i].head;
		while (trav != NULL)
		{
			if (trav->data.index == ref && trav->data.id != ref
					&& trav->data.visited != 1)
			{
				if (trav->data.room.end == 1)
					return (1);
				else if (trav->data.visited == 0)
				{
					push_back_g(trav->data, n, n_door);
					n++;
				}
			}
			trav = trav->next;
		}
		i++;
	}
	return (0);
}

t_data_g  visit_neighbour(t_graph **graph, t_node_g  **next_door)
{
	int     	visit;
	int     	i;
	t_node_g	*trav;
	t_graph		*temp_g;
	t_data_g	visitor;

	i = 0;
	temp_g = *graph;
	visit = pop_g(next_door);
	while (i < temp_g->v)
	{
		trav = temp_g->array[i].head;
		while (trav != NULL)
		{
			if (trav->data.id == visit)
			{
				trav->data.visited = 1;
				visitor = trav->data;
			}
			trav = trav->next;
		}
		i++;
	}
	free(*next_door);
	return (visitor);
}
void    path_finder(t_graph **graphs, /*t_node_r *head*/ t_node_g **path)
{
	t_node_g  *n_door;
	t_data_g  visited;
	int     n;

	n = 1;
	n_door = NULL;
	visited = find_start(*graphs);
	push_back_g(visited, n, path);
	check_neighbour(*graphs, 1, &n_door, 1);
	visited = visit_neighbour(graphs, &n_door);
	push_back_g(visited, ++n, path);
	while (visited.room.end !=  1)
	{
		if (check_neighbour(*graphs, visited.id, &n_door, 1) == 1)
		{
			visited.room.end = 1;
			push_back_g(find_end(*graphs).data, ++n, path);
		}
		else
		{
			visited = visit_neighbour(graphs, &n_door);
			push_back_g(visited, ++n, path);
		}
	}
}

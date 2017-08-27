/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 13:39:04 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/19 09:07:41 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//adjacency list

#include "lem_in.h"
#include <math.h>
#include <stdio.h>

void	free_2char(char **arr)
{
	int i;
	i = 0;
	while (arr)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int		distance(int src, int dst, t_node_r *head)
{
	t_node_r		*temp;
	t_point	a;
	t_point	b;

	temp = head;
	while (temp)
	{
		if (temp->data.room == src)
			a = temp->data.point;
		if (temp->data.room == dst)
			b = temp->data.point;
		temp = temp->next;
	}
	return ((int)sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

static t_node_g	*c_node(int x, int src, int dst, t_node_r *head) 
{
	t_node_g	*q; //for graph
	t_node_r	*temp;//link list

	if(!(q = (t_node_g *)malloc(sizeof(t_node_g))))
		return (NULL);
	q->data.id = x;
//	q->data.room.room = x;
//	q->data.index = src;
	q->data.distance = distance(src, dst, head);
	temp = head;
	while (temp)
	{
		if (temp->data.start == 1 && temp->data.room == x)
			q->data.room.start = 1;
		if (q->data.room.start == 1)
			q->data.visited = 1;
		if (temp->data.end == 1 && temp->data.room == x)
			q->data.room.end = 1;
		temp = temp->next;
	}	
	q->next = NULL;
	return (q);
}

void		add_edge(t_graph *graph, int src, int dst, t_node_r *head)
{
	t_node_g *temp;

	temp = c_node(dst, src, dst, head);
	temp->data.index = src;
	temp->next = graph->array[src].head;
	graph->array[src].head = temp;
	temp = c_node(src, src, dst, head);
	temp->data.index = dst;
	temp->next = graph->array[dst].head;
	graph->array[dst].head = temp;
}

t_graph		*graph(int v)
{
	t_graph	*graph;
	int		i;

	if(!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	graph->v = v;
	if(!(graph->array = (t_list *)malloc(v * sizeof(t_list))))
		return (NULL);
	i = 0;
	while (i < v)
	{
		graph->array[i].head = NULL;
		i++;
	}
	return (graph);
}

void	print_graph(t_graph *graph)
{
	int			i;
	t_node_g	*trav;

	i = 0;
	while (i < graph->v)
	{
				printf("%d|", i);
		trav = graph->array[i].head;
		while (trav != NULL)
		{
			printf("-> %d(-%d-){-%d-}[-%d-]/-%d-/", trav->data.id,
					 trav->data.distance, trav->data.room.start,
				   	trav->data.room.end,	trav->data.visited);
			trav = trav->next;
		}
		printf(" \n");
		i++;
	}
}

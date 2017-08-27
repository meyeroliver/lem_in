/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:29:51 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/27 17:33:56 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	push_back(t_data_r data, int n, t_node_r **head)
{
	t_node_r	*temp1;
	t_node_r	*temp2;
	int			i;

	temp1 = (t_node_r*)malloc(sizeof(t_node_r));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = *head;
		*head = temp1;
		return;
	}
	temp2 = *head;
	i = 0;
	while (i < n - 2)
	{
		temp2 = temp2->next;
		i++;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

int		pop(t_node_r **head)
{
	t_node_r	*temp;
	int		id;

	if (*head == NULL)
		return (-1);
	temp = *head;
	id = temp->data.room;
	*head = temp->next;
	free(temp);
	return (id);
}
//remeber to remove this function
void	print_list(t_node_r *head)
{
	t_node_r	*temp;

	temp = head;
	while (temp)
	{
		printf("%d %d %d %d %d\n", temp->data.room, temp->data.point.x,
				temp->data.point.y, temp->data.start, temp->data.end);
		temp = temp->next;
	}
}

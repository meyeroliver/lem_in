/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:29:51 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/19 10:35:05 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	push_back_g(t_data_g data, int n, t_node_g **head)
{
	t_node_g	*temp1;
	t_node_g	*temp2;
	int		i;

	temp1 = (t_node_g*)malloc(sizeof(t_node_g));
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

int		pop_g(t_node_g **head)
{
	t_node_g	*temp;
	int		id;

	if (*head == NULL)
		return (-1);
	temp = *head;
	id = temp->data.id;
	*head = temp->next;
	free(temp);
	return (id);
}

void	print_list_g(t_node_g *head)
{
	t_node_g	*temp;

	temp = head;
	while (temp)
	{
		printf("%d\t", temp->data.id);
		temp = temp->next;
	}
}

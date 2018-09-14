/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:39:30 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/20 09:36:33 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void    push_back_a(t_data_a data, int n, t_node_a **head)
{
	t_node_a    *temp1;
	t_node_a    *temp2;
	int     i;

	temp1 = (t_node_a*)malloc(sizeof(t_node_a));
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

int     pop_a(t_node_a **head)
{
	t_node_a    *temp;
	int     ant;

	if (*head == NULL)
		return (-1);
	temp = *head;
	ant = temp->data.id;
	*head = temp->next;
	free(temp);
	return (ant);
}

int		colony_size(t_node_a *head)
{
	t_node_a    *temp;
	int			i;

	temp = head;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void    print_list_a(t_node_a *head)
{
	t_node_a    *temp;

	temp = head;
	printf("\nANTS\n");
	while (temp)
	{
		printf("%d : %d\t", temp->data.id, temp->data.index);
		temp = temp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:36:20 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/27 16:40:12 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"

/***************************************/
/* this is for a list that will contain*/
/* the info of the rooms               */
/***************************************/
typedef struct      s_point
{
	int             x;
	int             y;
}                   t_point;

typedef struct      s_data_r
{
	int             room;
	int             start;
	int             end;
	t_point         point;
}                   t_data_r;

typedef struct      s_node_r
{
	t_data_r		data;
	struct s_node_r *next;
}                   t_node_r;

/*********************************/
/*	FILE_HANDLING.C              */
/*********************************/
/*********************************/
void	print_list(t_node_r *head);
void    push_back(t_data_r data, int n, t_node_r **head);
#endif

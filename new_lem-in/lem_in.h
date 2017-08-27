/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:36:20 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/27 17:34:23 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"

typedef	struct		s_check
{
	int				ants;
	int				start;
	int				end;
	int				room;
}					t_check;
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
int   open_file(char *filename);
void    close_file(int fd, char *filename);
void        file_handling(char  *filename);
t_check     checks(char *line, t_check check, t_node_r **head);
int break_up(int fd, t_node_r **head);
int     err_handling(t_node_r *head, int ants, int rooms);
/*********************************/
void	print_list(t_node_r *head);
void    push_back(t_data_r data, int n, t_node_r **head);
#endif

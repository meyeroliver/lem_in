/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:36:20 by omeyer            #+#    #+#             */
/*   Updated: 2018/09/14 14:38:59 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
/* These structs are involved in */
/* the creation pf the graph     */
/*********************************/

typedef struct		s_data_g
{
	int				id;
	int				index;
	int				visited;
	int				distance;
	t_data_r		room;
}					t_data_g;

typedef struct      s_node_g
{
	t_data_g		data;		
	struct s_node_g *next;
}                   t_node_g;

typedef struct      s_list
{
	t_node_g        *head;
}                   t_list;

typedef struct      s_graph
{
	int             v;
	t_list          *array;
}                   t_graph;

typedef	struct		s_check
{
	int				ants;
	int				start;
	int				end;
	int				room;
}					t_check;
/*********************************/
/*	This struct is involved in   */
/*	the creation of the ants     */
/*********************************/
typedef struct		s_data_a
{
	int				id;
	int				index;
}					t_data_a;

typedef struct		s_node_a
{
	t_data_a		data;
	struct s_node_a		*next;	
}					t_node_a;
/*********************************/
/*	FILE_HANDLING.C              */
/*********************************/
void	file_handling(char  *filename);
int		break_up(int fd, t_node_r **head, t_graph **graphs, t_node_a **head_a);
int		error_handling(t_node_r *head, int ants, int room);
t_check     checks(char *line, t_check check, t_node_r **head);
/*********************************/
/*	ROOM_LIST.C*/
/*********************************/
void	print_list(t_node_r *head);
void    push_back(t_data_r data, int n, t_node_r **head);
/*********************************/
/*	GRAPHS.C					 */
/*********************************/
t_graph     *graph(int v);
void    	add_edge(t_graph *graph, int src, int dst, t_node_r *head);
void    	print_graph(t_graph *graph);
/**********************************/
/*	PATH_FINDER					  */
/**********************************/
//t_data_r      find_start(t_node_r *head);
t_data_g    find_start(t_graph *graph);
t_node_g    find_end(t_graph *graph);
int     check_neighbour(t_graph *g, int ref, t_node_g  **n_door, int n);
t_data_g  visit_neighbour(t_graph **graph, t_node_g  **next_door);
void    path_finder(t_graph **graphs, /*t_node_r *head,*/ t_node_g **path);
/**********************************/
/*	PATH_LIST					  */
/**********************************/
void    push_back_g(t_data_g data, int n, t_node_g **head);
int     pop_g(t_node_g **head);
void    print_list_g(t_node_g *head_g);
/**********************************/
/*	ANT_LIST					  */
/**********************************/
void    push_back_a(t_data_a data, int n, t_node_a **head);
int     pop_a(t_node_a **head);
void    print_list_a(t_node_a *head_a);
void    create_ants(int ants, t_node_a **head, t_graph *graph);
int     colony_size(t_node_a *head);
/***********************************/
/*	MOVE_ANTS					   */
/***********************************/
void    move_ants(t_node_a **ants, t_node_g **path, t_graph *graph);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:46:30 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:30:17 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

typedef	struct		s_room
{
	int		searched;
	struct	s_room	*branch;
	struct	s_room	*parent;
	struct	s_room	*next;
	char		name[0];
}			t_room;

typedef	struct		s_queue
{
	char	*name;
	struct	s_queue	*next;
}			t_queue;

typedef	struct		s_path
{
	char	*name;
	struct	s_path	*next;
}			t_path;

typedef	struct		s_work
{
	int	ants;
	char	**ptr;
	char	**ptr2;
	char	*start;
	char	*end;
	char	*line;
	char	*tmp;
	t_path	*path;
	t_queue	*queue;
	t_room	*rooms;
	t_room	*current;
	t_room	*branch;
}			t_work;

void    add_room(t_room **head, char *room);
t_room	*get_room(t_room *rooms, char *name);
void	empty_line(char *line, int *error);
void enqueue(t_queue **head, char *room);
char	*dequeue(t_queue **head);
void	move_ants(t_work *work);
void add_path(t_path **head, char *room);
void   print_path(t_room *root, t_path **path);
void	start_endd(t_work *var, char *line, int *start_end, int *error);
void	check_cord(char *x, char *y, int *error);
void	connect(t_room *rooms, char *r1, char *r2, int *error);
void	ptr_free(void **ptr);
void	free_rooms(t_room *rm);
void	free_q(t_queue *q);
void	free_p(t_path *p);
void	freevar(t_work *var);
char	*free_trim(char *tmp);

#endif

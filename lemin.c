/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:42:58 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/30 15:29:47 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_work	*init(void)
{
	t_work	*new;

	new = (t_work *)malloc(sizeof(t_work));
	new->start = NULL;
	new->end = NULL;
	new->path = NULL;
	new->queue = NULL;
	new->ants = 0;
	new->rooms = NULL;
	return (new);
}

void	map_info(t_work *work, int *error, int *start_end)
{
	if (work->ants == 0)
	{
		check_cord(work->line, NULL, error);
		work->ants = ft_atoi(work->line);
	}
	work->ptr = ft_strsplit(work->line, ' ');
	work->ptr2 = ft_strsplit(work->line, '-');
	if (work->ptr)
		start_endd(work, ft_strdup(work->ptr[0]), start_end, error);
	if (ft_strncmp(work->line, "##start", 7) == 0 &&
			(!work->line[7] || work->line[7] == '#'))
		*start_end = 1;
	if (ft_strncmp(work->line, "##end", 5) == 0 &&
			(!work->line[5] || work->line[5] == '#'))
		*start_end = 2;
	if (work->ptr[0] && work->ptr[1] && work->ptr[2] && !work->ptr[3])
	{
		check_cord(work->ptr[1], work->ptr[2], error);
		if (work->ptr[0][0] == 'L')
			*error = 1;
		(work->ptr[0][0] == '#') ? 0 : add_room(&work->rooms, work->ptr[0]);
	}
	if (work->ptr2[0] && work->ptr2[1] && !work->ptr2[2])
		connect(work->rooms, work->ptr2[0], work->ptr2[1], error);
}

void	read_file(t_work *work, int *error)
{
	int	start_end;

	start_end = 0;
	while (get_next_line(0, &work->line))
	{
		if (ft_strlen(work->line))
			ft_putendl(work->line);
		work->line = free_trim(work->line);
		empty_line(work->line, error);
		(!(*error)) ? map_info(work, error, &start_end) : 0;
		(!(*error)) ? ptr_free((void *)work->ptr) : 0;
		(!(*error)) ? ptr_free((void *)work->ptr2) : 0;
		(work->line) ? free(work->line) : 0;
	}
}

void	thee_algo(t_work *work)
{
	work->current = get_room(work->rooms, work->start);
	enqueue(&work->queue, work->current->name);
	while (work->queue != NULL)
	{
		work->tmp = dequeue(&work->queue);
		work->current = get_room(work->rooms, work->tmp);
		if (ft_strcmp(work->tmp, work->end) == 0)
		{
			print_path(work->current, &work->path);
			break ;
		}
		while (work->current->branch)
		{
			work->branch = get_room(work->rooms, work->current->branch->name);
			if (!work->branch->searched)
			{
				work->branch->parent = work->current;
				enqueue(&work->queue, work->branch->name);
			}
			work->current->branch = work->current->branch->next;
		}
		work->current->searched = 1;
	}
}

int		main(void)
{
	t_work	*work;
	int		error;

	error = 0;
	work = init();
	read_file(work, &error);
	if (work->start && work->rooms && work->end && !error)
		thee_algo(work);
	ft_putchar('\n');
	(work->path) ? move_ants(work) : ft_putendl("ERROR");
	freevar(work);
	return (0);
}

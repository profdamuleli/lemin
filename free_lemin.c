/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:53:56 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:36:47 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	ptr_free(void **ptr)
{
	int	i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

void	free_rooms(t_room *rm)
{
	t_room *tmp;

	tmp = rm;
	while (rm)
	{
		rm = rm->next;
		free(tmp);
		(tmp->branch) ? free_rooms(tmp->branch) : 0;
		tmp = rm;
	}
}

void	free_q(t_queue *q)
{
	t_queue *tmp;

	tmp = q;
	while (q)
	{
		q = q->next;
		free(tmp);
		tmp = q;
	}
}

void	free_p(t_path *p)
{
	t_path *tmp;

	tmp = p;
	while (p)
	{
		p = p->next;
		free(tmp);
		tmp = p;
	}
}

void	freevar(t_work *var)
{
	(var->start) ? free(var->start) : 0;
	(var->end) ? free(var->end) : 0;
	(var->rooms) ? free_rooms(var->rooms) : 0;
	(var->queue) ? free_q(var->queue) : 0;
	(var->path) ? free_p(var->path) : 0;
	free(var);
}

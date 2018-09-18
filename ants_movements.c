/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:25:20 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:35:51 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	print_ants(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant + 1);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

int		ants_move(t_work *work, t_path *path, int ant, int iter)
{
	int	print;

	print = iter - ant;
	while (path && print)
	{
		if (print == 1)
		{
			print_ants(ant, path->name);
			if (ant + 1 == work->ants && ft_strcmp(work->end, path->name) == 0)
				return (1);
		}
		print--;
		path = path->next;
	}
	return (0);
}

void	move_ants(t_work *work)
{
	int		iter;
	int		finished;
	int		ant;
	t_path	*path;

	iter = 1;
	finished = 0;
	path = work->path->next;
	while (!finished)
	{
		ant = -1;
		while (++ant < work->ants)
			finished = ants_move(work, path, ant, iter);
		ft_putchar('\n');
		iter++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:31:37 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 10:33:59 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char	*comments(char *tmp)
{
	int i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
		{
			tmp[i] = '\0';
			break ;
		}
	}
	return (tmp);
}

void	connect(t_room *rooms, char *r1, char *r2, int *error)
{
	t_room *room1;
	t_room *room2;

	room1 = get_room(rooms, comments(r1));
	room2 = get_room(rooms, comments(r2));
	if (room1 && room2)
	{
		add_room(&room1->branch, comments(r2));
		add_room(&room2->branch, comments(r1));
	}
	else
		*error = 1;
}

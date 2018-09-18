/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:38:08 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:29:56 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_room	*add_new(char *room)
{
	t_room	*tmp;

	tmp = malloc(sizeof(t_room) + sizeof(char) +
	ft_strlen(room) + 1);
	ft_strcpy(tmp->name, room);
	tmp->searched = 0;
	tmp->branch = NULL;
	tmp->parent = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	add_room(t_room **head, char *room)
{
	t_room	*current;

	current = *head;
	if (!*head)
	{
		(*head) = add_new(room);
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_room) + sizeof(char) +
	ft_strlen(room) + 1);
	ft_strcpy(current->next->name, room);
	current->next->searched = 0;
	current->next->branch = NULL;
	current->next->parent = NULL;
	current->next->next = NULL;
}

t_room	*get_room(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strcmp(name, rooms->name) == 0)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:18:01 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:37:18 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	enqueue(t_queue **head, char *room)
{
	t_queue	*current;

	current = *head;
	if (*head == NULL)
	{
		(*head) = malloc(sizeof(t_queue));
		(*head)->name = room;
		(*head)->next = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_queue));
	current->next->name = room;
	current->next->next = NULL;
}

char	*dequeue(t_queue **head)
{
	char	*ret;
	t_queue *tmp;

	if (*head == NULL)
		return (NULL);
	tmp = *head;
	*head = tmp->next;
	ret = tmp->name;
	free(tmp);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:17:43 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:37:09 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	add_path(t_path **head, char *room)
{
	t_path	*current;

	current = *head;
	if (*head == NULL)
	{
		(*head) = malloc(sizeof(t_path));
		(*head)->name = room;
		(*head)->next = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_path));
	current->next->name = room;
	current->next->next = NULL;
}

void	print_path(t_room *root, t_path **path)
{
	if (root == NULL)
		return ;
	print_path(root->parent, path);
	add_path(path, root->name);
}

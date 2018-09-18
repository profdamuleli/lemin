/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:34:27 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:36:24 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void	empty_line(char *line, int *error)
{
	int	len;

	len = ft_strlen(line);
	if (!len)
		*error = 1;
}

void	start_endd(t_work *var, char *line, int *start_end, int *error)
{
	if (*start_end == 1)
	{
		if (var->start != NULL)
			*error = 1;
		var->start = line;
	}
	if (*start_end == 2)
	{
		if (var->end != NULL)
			*error = 1;
		var->end = line;
	}
	*start_end = 0;
}

void	check_cord(char *x, char *y, int *error)
{
	if (x != NULL)
	{
		while (*x && *x != '#')
		{
			if (!ft_isdigit(*x))
				*error = 1;
			x++;
		}
	}
	if (y != NULL)
	{
		while (*y && *y != '#')
		{
			if (!ft_isdigit(*y))
				*error = 1;
			y++;
		}
	}
}

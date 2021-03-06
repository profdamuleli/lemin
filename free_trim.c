/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_trim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:03:47 by ldamulel          #+#    #+#             */
/*   Updated: 2018/04/03 11:36:57 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char	*free_trim(char *tmp)
{
	char	*ret;

	ret = ft_strtrim(tmp);
	(tmp) ? free(tmp) : 0;
	return (ret);
}

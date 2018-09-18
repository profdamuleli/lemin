/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:55:07 by ldamulel          #+#    #+#             */
/*   Updated: 2017/07/20 16:08:40 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t s2_len;
	size_t s1_len;

	s2_len = ft_strlen(s2);
	s1_len = ft_strlen(s1);
	if (size < s1_len + 1)
		return (size + s2_len);
	if (size == s1_len + 1)
		return (s1_len + s2_len);
	ft_memcpy(s1 + s1_len, s2, size - s1_len - 1);
	s1[size - 1] = '\0';
	return (s1_len + s2_len);
}

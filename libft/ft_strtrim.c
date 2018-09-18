/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:41:03 by ldamulel          #+#    #+#             */
/*   Updated: 2017/06/10 14:15:34 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_first_not_white(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	return ((char *)&s[i]);
}

static char		*get_last_not_white(char const *s)
{
	int	i;

	i = (int)(ft_strlen(s)) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	if (i == -1)
		return (0);
	return ((char *)&s[i]);
}

char			*ft_strtrim(char const *s)
{
	char	*first_not_white;
	char	*last_not_white;
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	first_not_white = get_first_not_white(s);
	last_not_white = get_last_not_white(s);
	if (first_not_white > last_not_white)
	{
		ret = ft_strnew(0);
		if (!ret)
			return (NULL);
		return (ret);
	}
	len = last_not_white - first_not_white + 1;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, first_not_white, len);
	return (ret);
}

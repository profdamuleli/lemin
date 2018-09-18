/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:30:06 by ldamulel          #+#    #+#             */
/*   Updated: 2017/07/20 14:30:08 by ldamulel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	lngnbr;

	lngnbr = (long)n;
	if (lngnbr < 0)
	{
		ft_putchar('-');
		lngnbr *= -1;
	}
	if (lngnbr >= 10)
	{
		ft_putnbr(lngnbr / 10);
		ft_putnbr(lngnbr % 10);
	}
	else
	{
		ft_putchar(lngnbr + '0');
	}
}

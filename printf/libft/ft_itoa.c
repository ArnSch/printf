/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:17:20 by aschenk           #+#    #+#             */
/*   Updated: 2014/12/31 15:24:36 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigit(int nb)
{
	int		digit;

	digit = 0;
	if (nb < 0)
	{
		digit++;
		nb *= -1;
	}
	while (nb / 10 != 0)
	{
		digit++;
		nb /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*num;
	int		last_index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	last_index = 0;
	i = 0;
	i = ft_countdigit(n) + 1;
	if (!(num = ft_memalloc((size_t)(i))))
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
		last_index = 1;
	}
	num[i] = '\0';
	while (i-- > last_index)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

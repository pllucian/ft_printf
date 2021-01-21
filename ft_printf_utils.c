/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:47:50 by pllucian          #+#    #+#             */
/*   Updated: 2021/01/21 04:57:40 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ulltoa_base(unsigned long long nbr, int base)
{
	char				*str;
	int					len;
	unsigned long long	nbr2;

	len = 1;
	nbr2 = nbr;
	while (nbr /= base)
		len++;
	if (!(str = (char*)(malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	str[len--] = '\0';
	if (!nbr)
		str[len] = '0';
	while (nbr2)
	{
		if (nbr2 % base < 10)
			str[len--] = nbr2 % base + '0';
		else
			str[len--] = nbr2 % base + 'A' - 10;
		nbr2 /= base;
	}
	return (str);
}

char		*ft_uitoa_base(unsigned int nbr, int base)
{
	char			*str;
	int				len;
	unsigned int	nbr2;

	len = 1;
	nbr2 = nbr;
	while (nbr /= base)
		len++;
	if (!(str = (char*)(malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	str[len--] = '\0';
	if (!nbr)
		str[len] = '0';
	while (nbr2)
	{
		if (nbr2 % base < 10)
			str[len--] = nbr2 % base + '0';
		else
			str[len--] = nbr2 % base + 'A' - 10;
		nbr2 /= base;
	}
	return (str);
}

char		*ft_str_tolower(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (ptr);
}

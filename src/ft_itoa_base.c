/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:24:28 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/04 10:40:28 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// J'ai quelques caracteres non souhaites parfois... fonction a revoir.

uintmax_t		ft_abs(intmax_t n)
{
	return (n < 0 ? -n : n);
}

char			*ft_itoa_base(intmax_t nbr, int base)
{
	static char	convert[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};
	long		i;
	uintmax_t	n;
	uintmax_t	converted_nbr[64];
	char		*result;

	i = 0;
	n = ft_abs(nbr);
	while (n > 0)
	{
		converted_nbr[i++] = n % base;
		n /= base;
	}
	result = (char*)malloc(sizeof(char) * --i);
	if (nbr < 0 && base == 10)
	{
		result[0] = '-';
		n = 1;
	}
	while (i >= 0)
		result[n++] = convert[converted_nbr[i--]];
	return (result);
}

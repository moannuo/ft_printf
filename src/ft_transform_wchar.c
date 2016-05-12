/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:44:49 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/12 10:45:17 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		fresh[i++] = wchar;
	else if (size == 2)
	{
		fresh[i++] = (wchar >> 6) + 0xC0;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (wchar >> 12) + 0xE0;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		fresh[i++] = (wchar >> 18) + 0xF0;
		fresh[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

char	*ft_transform_wchar_in_char(wchar_t *S)
{
	char	*fresh;
	int		i;
	int		k;
	int		len;

	i = 0;
	k = 0;
	len = ft_wbytelen(S);
	fresh = (char*)malloc(sizeof(char) * len);
	fresh[len] = '\0';
	while (S[k])
	{
		i = ft_putwchar_in_char(S[k], fresh, i);
		k++;
	}
	return (fresh);
}

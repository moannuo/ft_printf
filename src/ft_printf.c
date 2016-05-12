/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:18:27 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/12 16:08:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** This our main function, it tooks our string and arguments, displays them or
** call subsidiaries functions to manage flags.
*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flag		f;
	int			i;

	va_start(ap, format);
	i = -1;
	f.ret = 0;
	ft_bufset();
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f.frmt = (char*)&format[++i];
			if (ft_dispatcher(&f, &ap) == -1)
				break ;
			i += f.ndx;
		}
		else if (format[i] != '\0' && format[i] != '%')
			ft_buf(format[i], &f);
	}
	if (g_i > 0)
		ft_display(&f);
	va_end(ap);
	return (f.ret);
}

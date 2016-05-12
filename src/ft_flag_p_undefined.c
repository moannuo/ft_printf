/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p_undefined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:42:01 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/12 13:57:39 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_handler_p(t_flag *f, va_list *ap)
{
	static int	mask_p[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->fla[2] = 1;
	ft_apply_mask(f, mask_p);
	f->arg = ft_strlwr(ft_itoa_base((uintmax_t)va_arg(*ap, void*), 16));
	if (f->fla[0] == -1 && f->arg[0] == '0')
	{
		ft_putchar('0', f);
		ft_putchar('x', f);
	}
	else
		ft_handler_numb(f);
	return (0);
}

int		ft_handler_undefined(t_flag *f)
{
	static int	mask_und[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c[2];

	f->fla[0] = 0;
	if (f->spe == 0)
	{
		f->ret = 0;
		return (f->ret);
	}
	c[0] = f->spe;
	c[1] = '\0';
	f->arg = c;
	ft_apply_mask(f, mask_und);
	return (ft_handler_char(f));
}
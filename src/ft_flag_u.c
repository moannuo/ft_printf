/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:44:48 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/04 14:58:19 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char			*ft_modifier_u(t_flag *f, va_list *ap)
{
	intmax_t	data;

	if (f->fla[7] == 1)
		data = (intmax_t)((unsigned char)va_arg(*ap, int));
	if (f->fla[8] == 1)
		data = (intmax_t)((unsigned short)va_arg(*ap, int));
	if (f->fla[10] == 1)
		data = (intmax_t)(va_arg(*ap, unsigned long));
	if (f->fla[9] == 1)
		data = (intmax_t)(va_arg(*ap, unsigned long long));
	if (f->fla[11] == 1)
		data = (intmax_t)(va_arg(*ap, uintmax_t));
	if (f->fla[12] == 1)
		data = (intmax_t)(va_arg(*ap, size_t));
	else
		data = (intmax_t)(va_arg(*ap, unsigned int));
	return (ft_itoa_base(data, 10));
}

int			ft_handler_u(t_flag *f, va_list *ap)
{
	static int	mask_u[13] = {0, 0, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1};

	ft_apply_mask(f, mask_u);
	f->arg = ft_modifier_u(f, ap);
	ft_handler(f);
	return (0);
}
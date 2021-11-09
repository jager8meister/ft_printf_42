/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:32:53 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:10:20 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_source.h"

void	c_porcessor(t_print_call_element *call_elem)
{
	if (call_elem->c == '-' && call_elem->dot == 0)
		call_elem->minus = 1;
	if (call_elem->c == '.')
		call_elem->dot = 1;
	if (call_elem->width == 0 && call_elem->c == '0')
		call_elem->zero = 1;
	else if (ft_isdigit(call_elem->c) && !call_elem->dot)
		call_elem->width = 10 * call_elem->width + ((int)call_elem->c - 48);
	if (ft_isdigit(call_elem->c) && call_elem->dot)
	{
		call_elem->precision = (call_elem->precision == -1)
		? 0 : call_elem->precision;
		call_elem->precision = 10 * call_elem->precision
		+ ((int)call_elem->c - 48);
	}
}

void	star_processor(t_print_call_element *call_elem, va_list *argp)
{
	if (call_elem->c == '*')
	{
		if (!call_elem->dot)
		{
			call_elem->width = va_arg(*argp, int);
			if (call_elem->width < 0)
			{
				call_elem->minus = 1;
				call_elem->width = -call_elem->width;
			}
		}
		else
		{
			call_elem->precision = va_arg(*argp, int);
			if (call_elem->precision < 0)
			{
				call_elem->was_negative_precision = 1;
				call_elem->precision = -1;
			}
		}
	}
}

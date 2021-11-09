/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_printf_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:31:56 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:09:39 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_source.h"

void	print_call_data_default(t_print_call_element *print_call_elem)
{
	print_call_elem->width = 0;
	print_call_elem->precision = -1;
	print_call_elem->zero = 0;
	print_call_elem->minus = 0;
	print_call_elem->dot = 0;
	print_call_elem->number = 0;
	print_call_elem->was_negative_precision = 0;
	print_call_elem->valid_args = "0123456789-.*";
	print_call_elem->str_len = 0;
}

void	callin_default_data(t_call_element *call_d,
t_print_call_element *p_call_d)
{
	if (p_call_d->dot == 1 && p_call_d->precision == -1
	&& p_call_d->was_negative_precision == 0)
		p_call_d->precision = 0;
	p_call_d->exit = 0;
	call_d->was_negative_precision = p_call_d->was_negative_precision;
	call_d->minus = p_call_d->minus;
	call_d->precision = p_call_d->precision;
	call_d->zero = p_call_d->zero;
	call_d->width = p_call_d->width;
}

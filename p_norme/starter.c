/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:08:14 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:08:34 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_source.h"

void	p_default_data(t_p_element *elem_data, t_call_element *call)
{
	elem_data->power = 1;
	elem_data->was_printed = 0;
	elem_data->all_hex_digits = "0123456789abcdef";
	elem_data->num = call->palka;
	elem_data->size = p_size_of_digit(elem_data->num) + 2;
	elem_data->was_negative_precision = call->was_negative_precision;
	elem_data->precision = call->precision;
	elem_data->width = call->width;
	elem_data->zero = call->zero;
	elem_data->minus = call->minus;
}

void	p_checkings(t_p_element *elem_data)
{
	if (elem_data->num == 0 && elem_data->precision == 0)
		elem_data->size = 2;
	if (elem_data->was_negative_precision == 1
	&& elem_data->num == 0 && elem_data->zero == 0)
		elem_data->precision = 1;
}

void	p_power_finder(t_p_element *elem_data)
{
	while (elem_data->power <= elem_data->num)
		elem_data->power *= 16;
	elem_data->power /= 16;
}

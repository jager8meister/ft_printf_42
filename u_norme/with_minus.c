/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:08:33 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:12:16 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u_source.h"

int		u_minus_with_precision(t_unsigned_int_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if (elem_data->minus == 1 && elem_data->precision != -1)
	{
		diff = 0;
		if (elem_data->width > elem_data->precision)
			diff = (elem_data->precision > elem_data->size) ?
			(elem_data->width - elem_data->precision) :
			(elem_data->width - elem_data->size);
		while (diff > 0)
		{
			write(1, " ", 1);
			diff--;
			str_len++;
		}
	}
	return (str_len);
}

int		u_minus_without_precision(t_unsigned_int_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if ((elem_data->minus == 1) && (elem_data->precision == -1))
	{
		diff = 0;
		if (elem_data->width > elem_data->size)
			diff = elem_data->width - elem_data->size;
		if (elem_data->size == 0)
		{
			diff--;
			write(1, "0", 1);
			str_len += 1;
		}
		while (diff > 0)
		{
			write(1, " ", 1);
			diff--;
			str_len++;
		}
	}
	return (str_len);
}

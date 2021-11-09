/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:09:07 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:12:20 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u_source.h"

int		u_no_minus_with_precision(t_unsigned_int_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if ((elem_data->minus == 0) && (elem_data->precision != -1))
	{
		diff = 0;
		if ((elem_data->width > elem_data->precision)
			&& (elem_data->width > elem_data->size))
			diff = (elem_data->precision >= elem_data->size) ?
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

int		u_no_minus_no_precision(t_unsigned_int_element *e_d)
{
	int diff;
	int str_len;

	str_len = 0;
	if ((e_d->minus == 0) && (e_d->precision == -1) && !(diff = 0))
	{
		if (e_d->width > e_d->size)
			diff = e_d->width - e_d->size;
		if (e_d->size == 0)
		{
			diff--;
			write(1, "0", 1);
			str_len += 1;
		}
		while (diff > 0)
		{
			if (e_d->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			diff--;
			str_len++;
		}
	}
	return (str_len);
}

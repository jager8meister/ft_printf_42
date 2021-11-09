/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:08:48 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:12:02 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u_source.h"

void	u_precision_check(t_unsigned_int_element *elem_data)
{
	if ((elem_data->num == 0 && elem_data->precision == -1
		&& elem_data->zero == 0)
		|| (elem_data->num == 0 &&
		elem_data->width == 0 && elem_data->precision == -1)
		|| (elem_data->was_negative_precision == 1
		&& elem_data->num == 0 && elem_data->zero == 0))
		elem_data->precision = 1;
}

int		u_precision_zeros(t_unsigned_int_element *elem_data)
{
	int diff;
	int str_len;

	str_len = 0;
	if ((elem_data->precision - elem_data->size) > 0)
	{
		diff = elem_data->precision - elem_data->size;
		while (diff > 0)
		{
			write(1, "0", 1);
			diff--;
			str_len++;
		}
	}
	return (str_len);
}

void	u_power_finder(t_unsigned_int_element *elem_data)
{
	while (elem_data->power <= elem_data->num && elem_data->num != 0)
		elem_data->power *= 10;
	elem_data->power /= 10;
}

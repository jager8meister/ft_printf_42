/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:28:38 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:05:28 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "di_source.h"

int			di_minus_with_precision(t_di_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if (elem_data->minus == 1 && elem_data->precision != -1)
	{
		diff = 0;
		if (elem_data->width > elem_data->precision)
		{
			diff = (elem_data->precision > elem_data->size) ?
			(elem_data->width - elem_data->precision)
			: (elem_data->width - elem_data->size);
			if (elem_data->negative)
				diff--;
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

int			di_minus_without_precision(t_di_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if ((elem_data->minus == 1) && (elem_data->precision == -1))
	{
		diff = 0;
		if (elem_data->width > elem_data->size)
		{
			diff = elem_data->width - elem_data->size;
			if (elem_data->negative)
				diff--;
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

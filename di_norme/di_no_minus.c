/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_no_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:28:51 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:05:42 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "di_source.h"

int			di_no_minus_with_precision(t_di_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if ((elem_data->minus == 0) && (elem_data->precision != -1))
	{
		diff = 0;
		if ((elem_data->width > elem_data->precision)
		&& (elem_data->width > elem_data->size))
		{
			diff = (elem_data->precision >= elem_data->size) ?
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

int			di_no_minus_no_precision_diff_src(int diff, int zero)
{
	int str_len;

	str_len = 0;
	while (diff > 0)
	{
		if (zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		diff--;
		str_len++;
	}
	return (str_len);
}

int			di_no_minus_no_precision(t_di_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if ((elem_data->minus == 0) && (elem_data->precision == -1))
	{
		diff = 0;
		if (elem_data->width > elem_data->size)
		{
			diff = elem_data->width - elem_data->size;
			if (elem_data->negative)
				diff--;
		}
		if (elem_data->l_num < 0 && elem_data->zero == 1)
		{
			write(1, "-", 1);
			elem_data->negative = 1;
			elem_data->l_num = di_abs_long(elem_data->l_num);
			elem_data->was_printed = 1;
			str_len++;
		}
		str_len += di_no_minus_no_precision_diff_src(diff, elem_data->zero);
	}
	return (str_len);
}

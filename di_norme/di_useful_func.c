/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_useful_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:29:50 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:06:22 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "di_source.h"

long long	di_abs_long(long long j)
{
	return (j < 0 ? -j : j);
}

int			di_size_of_digit(int num)
{
	long long	power;
	int			size;
	long long	l_num;

	power = 1;
	size = 0;
	l_num = (long long)num;
	if (num < 0)
		l_num = di_abs_long(l_num);
	while (power <= l_num)
	{
		power *= 10;
		size++;
	}
	return (size);
}

void		di_precision_checking(t_di_element *elem_data)
{
	if (elem_data->l_num == 0 && elem_data->width == 0 && elem_data->zero == 1
		&& elem_data->precision == -1)
	{
		elem_data->precision = 1;
		elem_data->width = 1;
	}
	if ((elem_data->was_negative_precision == 1 &&
		elem_data->l_num == 0 && elem_data->zero == 0) ||
		(elem_data->l_num == 0 && elem_data->precision == -1 &&
		elem_data->was_negative_precision == 0 && elem_data->zero == 0)
		|| (elem_data->was_negative_precision == 0 &&
		elem_data->l_num == 0 && elem_data->zero == 1 &&
		elem_data->precision == -1 && elem_data->minus == 1)
		|| (elem_data->was_negative_precision == 1 &&
		elem_data->l_num == 0 && elem_data->zero == 1
		&& elem_data->precision == -1 && elem_data->minus == 1))
		elem_data->precision = 1;
}

int			di_minus_check(t_di_element *elem_data)
{
	int str_len;

	str_len = 0;
	if (elem_data->l_num < 0 && elem_data->was_printed == 0)
	{
		write(1, "-", 1);
		elem_data->negative = 1;
		elem_data->l_num = di_abs_long(elem_data->l_num);
		str_len += 1;
	}
	return (str_len);
}

long long	di_power_finder(long long l_num)
{
	long long power;

	power = 1;
	while (power <= l_num)
		power *= 10;
	power /= 10;
	return (power);
}

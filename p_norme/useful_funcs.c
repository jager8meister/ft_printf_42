/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:08:59 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:08:42 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_source.h"

void	p_precision_zeros(t_p_element *elem_data, int *str_len)
{
	int diff;

	if ((elem_data->precision - elem_data->size) > 0)
	{
		diff = (elem_data->num != 0) ?
		(elem_data->precision - elem_data->size)
		: (elem_data->precision - 1);
		if (elem_data->num != 0 && elem_data->precision > elem_data->width
		&& elem_data->precision > elem_data->size)
			diff += 2;
		while (diff > 0)
		{
			write(1, "0", 1);
			diff--;
			*str_len += 1;
		}
	}
}

void	p_zero_check(t_p_element *elem_data, int *str_len)
{
	char c;

	if (elem_data->num == 0 && elem_data->precision != 0)
	{
		c = elem_data->all_hex_digits[0];
		write(1, &c, 1);
		*str_len += 1;
	}
}

void	p_writer(t_p_element *elem_data, int *str_len)
{
	char c;

	while (elem_data->power > 0)
	{
		c = elem_data->all_hex_digits[elem_data->num / elem_data->power];
		write(1, &c, 1);
		elem_data->num %= elem_data->power;
		elem_data->power /= 16;
		*str_len += 1;
	}
}

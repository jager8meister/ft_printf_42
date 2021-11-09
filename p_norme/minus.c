/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:08:04 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:07:43 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_source.h"

void	p_minus_w_precision(t_p_element *elem_data, int *str_len)
{
	int diff;

	if (elem_data->minus == 1 && elem_data->precision != -1)
	{
		diff = 0;
		if (elem_data->width > elem_data->precision)
			diff = (elem_data->precision > elem_data->size)
			? (elem_data->width - elem_data->precision)
			: (elem_data->width - elem_data->size);
		while (diff > 0)
		{
			write(1, " ", 1);
			diff--;
			*str_len += 1;
		}
	}
}

void	p_minus_no_precision(t_p_element *elem_data, int *str_len)
{
	int diff;

	if ((elem_data->minus == 1) && (elem_data->precision == -1))
	{
		diff = 0;
		if (elem_data->width > elem_data->size)
			diff = elem_data->width - elem_data->size;
		while (diff > 0)
		{
			write(1, " ", 1);
			diff--;
			*str_len += 1;
		}
	}
}

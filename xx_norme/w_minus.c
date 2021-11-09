/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_minus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:07:20 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:13:32 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xx_source.h"

int		xx_minus_w_precision(t_xx_element *elem_data)
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
			(elem_data->width - elem_data->precision) :
			(elem_data->width - elem_data->size);
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

int		xx_minus_no_precision(t_xx_element *elem_data)
{
	int str_len;
	int diff;

	str_len = 0;
	if ((elem_data->minus == 1) && (elem_data->precision == -1) && !(diff = 0))
	{
		if (elem_data->width > elem_data->size)
		{
			diff = elem_data->width - elem_data->size;
			if (elem_data->negative)
				diff--;
		}
		if (elem_data->size == 0)
		{
			diff--;
			write(1, "0", 1);
			str_len += 1;
		}
		while (diff-- > 0)
		{
			write(1, " ", 1);
			str_len++;
		}
	}
	return (str_len);
}

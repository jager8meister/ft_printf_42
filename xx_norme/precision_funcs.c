/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:12:22 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:13:11 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xx_source.h"

void	xx_precision_checking(t_xx_element *elem_data)
{
	if (elem_data->num == 0 &&
	elem_data->width == 0 && elem_data->precision == -1)
		elem_data->precision = 1;
	if (elem_data->was_negative_precision == 1
	&& elem_data->num == 0 && elem_data->zero == 0)
		elem_data->precision = 1;
	if (elem_data->was_negative_precision == 0
	&& elem_data->num == 0
	&& elem_data->zero == 0 && elem_data->precision == -1
	&& elem_data->width != 0)
		elem_data->precision = 1;
}

int		xx_precision_zeros(t_xx_element *elem_data)
{
	int str_len;
	int diff;

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

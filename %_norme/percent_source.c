/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:33:47 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 22:55:57 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "percent_source.h"

void	perc_default_data(t_percent_element *elem_data, t_call_element *call)
{
	elem_data->size = 1;
	elem_data->minus = call->minus;
	elem_data->width = call->width;
	elem_data->precision = call->precision;
	elem_data->zero = call->zero;
}

void	perc_percentage_source(t_percent_element *elem_data, int *str_len)
{
	int diff;

	diff = elem_data->width - elem_data->size;
	while (diff > 0)
	{
		if (elem_data->zero == 1 && elem_data->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		diff--;
		*str_len += 1;
	}
}

void	print_percentage(t_call_element *call, int *str_len)
{
	char				c;
	t_percent_element	elementik;

	perc_default_data(&elementik, call);
	c = '%';
	*str_len = 0;
	if (elementik.minus == 1)
	{
		write(1, &c, 1);
		*str_len += 1;
	}
	perc_percentage_source(&elementik, str_len);
	if (elementik.minus == 0)
	{
		write(1, &c, 1);
		*str_len += 1;
	}
}

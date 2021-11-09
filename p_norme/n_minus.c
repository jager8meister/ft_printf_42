/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_minus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:07:56 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:08:07 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_source.h"

void	p_n_minus_w_precision(t_p_element *elem_data, int *str_len)
{
	int diff;

	if ((elem_data->minus == 0) && (elem_data->precision != -1))
	{
		diff = 0;
		if ((elem_data->width > elem_data->precision)
		&& (elem_data->width > elem_data->size))
			diff = (elem_data->precision >= elem_data->size) ?
			(elem_data->width - elem_data->precision)
			: (elem_data->width - elem_data->size);
		while (diff > 0)
		{
			write(1, " ", 1);
			diff -= 1;
			*str_len += 1;
		}
	}
}

void	p_n_minus_n_precision_core(t_p_element *elem_data, int *str_len)
{
	int diff;

	diff = 0;
	if (elem_data->width > elem_data->size)
		diff = elem_data->width - elem_data->size;
	if (elem_data->zero == 1)
	{
		write(1, "0x", 2);
		*str_len += 2;
	}
	while (diff > 0)
	{
		if (elem_data->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		diff -= 1;
		*str_len += 1;
	}
	if (elem_data->zero == 0)
	{
		write(1, "0x", 2);
		*str_len += 2;
	}
}

void	p_n_minus_n_precision(t_p_element *elem_data, int *str_len)
{
	if ((elem_data->minus == 0) && (elem_data->precision == -1))
	{
		p_n_minus_n_precision_core(elem_data, str_len);
	}
	else
	{
		write(1, "0x", 2);
		*str_len += 2;
	}
}

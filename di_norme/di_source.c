/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:06:56 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:06:03 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "di_source.h"

int			di_zero_in_precision(t_di_element *elem_data)
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

int			di_number_writer(t_di_element *elem_data)
{
	int		str_len;
	char	c;

	str_len = 0;
	while (elem_data->power > 0)
	{
		if ((elem_data->l_num / elem_data->power) > 0)
		{
			c = elem_data->l_num / elem_data->power + '0';
			write(1, &c, 1);
			str_len += 1;
		}
		else
		{
			c = (elem_data->l_num / elem_data->power) * -1 + '0';
			write(1, &c, 1);
			str_len += 1;
		}
		elem_data->l_num %= elem_data->power;
		elem_data->power /= 10;
	}
	return (str_len);
}

void		print_number_with_flags(t_call_element *call, int *str_len)
{
	t_di_element elementik;

	*str_len = 0;
	elementik.zero = call->zero;
	elementik.minus = call->minus;
	elementik.precision = call->precision;
	elementik.width = call->width;
	elementik.num = call->num;
	elementik.was_negative_precision = call->was_negative_precision;
	elementik.power = 1;
	elementik.size = di_size_of_digit(call->num);
	elementik.negative = (call->num < 0) ? 1 : 0;
	elementik.was_printed = 0;
	elementik.l_num = (long long)call->num;
	di_precision_checking(&elementik);
	*str_len += di_no_minus_with_precision(&elementik);
	*str_len += di_no_minus_no_precision(&elementik);
	*str_len += di_minus_check(&elementik);
	*str_len += di_zero_in_precision(&elementik);
	elementik.power = di_power_finder(elementik.l_num);
	*str_len += di_number_writer(&elementik);
	*str_len += di_minus_with_precision(&elementik);
	*str_len += di_minus_without_precision(&elementik);
}

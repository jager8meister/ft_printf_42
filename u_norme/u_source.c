/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_source.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:17:28 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:11:39 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u_source.h"

static int	u_size_of_digit(unsigned int num)
{
	long long	power;
	int			size;

	power = 1;
	size = 0;
	while (power <= num)
	{
		power *= 10;
		size++;
	}
	return (size);
}

int			unsigned_int_number_writer(t_unsigned_int_element *elem_data)
{
	int		str_len;
	char	c;

	str_len = 0;
	while (elem_data->power > 0)
	{
		if ((elem_data->num / elem_data->power) > 0)
		{
			c = elem_data->num / elem_data->power + '0';
			write(1, &c, 1);
		}
		else
		{
			c = (elem_data->num / elem_data->power) * -1 + '0';
			write(1, &c, 1);
		}
		elem_data->num %= elem_data->power;
		elem_data->power /= 10;
		str_len++;
	}
	return (str_len);
}

void		print_unsigned_int_with_flags(t_call_element *call, int *str_len)
{
	t_unsigned_int_element	elementik;

	elementik.num = call->unsigned_num;
	elementik.power = 1;
	elementik.size = u_size_of_digit(call->unsigned_num);
	elementik.precision = call->precision;
	elementik.width = call->width;
	elementik.zero = call->zero;
	elementik.minus = call->minus;
	elementik.was_negative_precision = call->was_negative_precision;
	*str_len = 0;
	u_precision_check(&elementik);
	*str_len += u_no_minus_with_precision(&elementik);
	*str_len += u_no_minus_no_precision(&elementik);
	*str_len += u_precision_zeros(&elementik);
	u_power_finder(&elementik);
	*str_len += unsigned_int_number_writer(&elementik);
	*str_len += u_minus_with_precision(&elementik);
	*str_len += u_minus_without_precision(&elementik);
}

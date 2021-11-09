/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:58:41 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:13:38 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xx_source.h"

void	print_combine_hex_with_flags(t_call_element *call,
int size_of_symbols, int *str_len)
{
	t_xx_element	elementik;

	elementik.power = 1;
	elementik.num = call->unsigned_num;
	elementik.size = xx_size_of_digit(elementik.num);
	elementik.negative = (elementik.num < 0) ? 1 : 0;
	elementik.was_printed = 0;
	elementik.width = call->width;
	elementik.was_negative_precision = call->was_negative_precision;
	elementik.minus = call->minus;
	elementik.zero = call->zero;
	elementik.precision = call->precision;
	elementik.all_hex_digits = (size_of_symbols == 0)
	? "0123456789abcdef" : "0123456789ABCDEF";
	*str_len = 0;
	xx_precision_checking(&elementik);
	*str_len += xx_no_minus_w_precision(&elementik);
	*str_len += xx_no_minus_no_precision(&elementik);
	*str_len += xx_precision_zeros(&elementik);
	xx_power_finder(&elementik);
	*str_len += xx_hex_number_writer(&elementik);
	*str_len += xx_minus_w_precision(&elementik);
	*str_len += xx_minus_no_precision(&elementik);
}

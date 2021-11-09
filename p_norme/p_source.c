/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_source.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:41:57 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:08:19 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_source.h"

int			p_size_of_digit(unsigned long long num)
{
	unsigned long long	power;
	int					size;

	power = 1;
	size = 0;
	if (num == 0)
		size = 1;
	while (power <= num)
	{
		power *= 16;
		size += 1;
	}
	return (size);
}

void		print_p_with_flags(t_call_element *call, int *str_len)
{
	t_p_element	elementik;

	*str_len = 0;
	p_default_data(&elementik, call);
	p_checkings(&elementik);
	p_n_minus_w_precision(&elementik, str_len);
	p_n_minus_n_precision(&elementik, str_len);
	p_precision_zeros(&elementik, str_len);
	p_power_finder(&elementik);
	p_zero_check(&elementik, str_len);
	p_writer(&elementik, str_len);
	p_minus_w_precision(&elementik, str_len);
	p_minus_no_precision(&elementik, str_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:13:47 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:13:16 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xx_source.h"

int		xx_size_of_digit(unsigned int num)
{
	long long	power;
	int			size;

	power = 1;
	size = 0;
	while (power <= num)
	{
		power *= 16;
		size++;
	}
	return (size);
}

void	xx_power_finder(t_xx_element *elem_data)
{
	while (elem_data->power <= elem_data->num)
		elem_data->power *= 16;
	elem_data->power /= 16;
}

int		xx_hex_number_writer(t_xx_element *elem_data)
{
	int		str_len;
	char	c;

	str_len = 0;
	while (elem_data->power > 0)
	{
		c = elem_data->all_hex_digits[elem_data->num / elem_data->power];
		write(1, &c, 1);
		elem_data->num %= elem_data->power;
		elem_data->power /= 16;
		str_len++;
	}
	return (str_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:41:33 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:10:50 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_source.h"

int		s_no_minus_w_precision(t_str_element *e_d)
{
	int		str_len;
	int		diff;
	int		i;

	str_len = 0;
	if ((e_d->precision != -1) && (e_d->minus == 0) && !(i = 0))
	{
		if (e_d->width > e_d->precision && e_d->precision <= e_d->size)
		{
			diff = (e_d->precision > e_d->size)
			? (e_d->width - e_d->size) : (e_d->width - e_d->precision);
			s_space_writer(&diff, &str_len);
		}
		else if (e_d->precision > e_d->size)
		{
			diff = e_d->width - e_d->size;
			s_space_writer(&diff, &str_len);
		}
		while ((i < e_d->precision) && (e_d->str[i] != '\0'))
		{
			write(1, &e_d->str[i++], 1);
			str_len++;
		}
	}
	return (str_len);
}

int		s_minus_w_precision(t_str_element *elem_data)
{
	int		str_len;
	int		diff;
	char	ch;
	int		i;

	str_len = 0;
	if ((elem_data->precision != -1) && (elem_data->minus == 1))
	{
		i = 0;
		while ((i < elem_data->precision) && (elem_data->str[i] != '\0'))
		{
			ch = elem_data->str[i];
			write(1, &ch, 1);
			i++;
			str_len++;
		}
		if (elem_data->width > elem_data->precision)
		{
			diff = elem_data->width - elem_data->precision;
			s_space_writer(&diff, &str_len);
		}
	}
	return (str_len);
}

int		s_no_precision_func(t_str_element *elem_data)
{
	int		str_len;
	int		diff;
	char	ch;
	int		i;

	str_len = 0;
	if (elem_data->precision == -1)
	{
		diff = elem_data->width - elem_data->size;
		if (elem_data->minus == 0)
			s_space_writer(&diff, &str_len);
		i = 0;
		while ((elem_data->str[i] != '\0'))
		{
			ch = elem_data->str[i];
			write(1, &ch, 1);
			i++;
			str_len++;
		}
		if (elem_data->minus != 0)
			s_space_writer(&diff, &str_len);
	}
	return (str_len);
}

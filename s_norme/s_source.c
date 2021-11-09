/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_source.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:02:24 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:11:01 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_source.h"

void	s_elementik_data(t_str_element *elem_data, t_call_element *call)
{
	elem_data->str = call->str;
	elem_data->size = s_size_of_str(call->str);
	elem_data->precision = call->precision;
	if (elem_data->precision > elem_data->size)
		elem_data->precision = elem_data->size;
	elem_data->width = call->width;
	elem_data->minus = call->minus;
}

void	s_null_data(t_call_element *null_call, t_call_element *call)
{
	char	*null_str;

	null_str = "(null)";
	null_call->str = null_str;
	null_call->minus = call->minus;
	null_call->precision = call->precision;
	null_call->width = call->width;
}

int		print_str(t_call_element *call)
{
	int				str_len;
	t_str_element	elementik;
	t_call_element	null_call;

	str_len = 0;
	if (call->str == NULL)
	{
		s_null_data(&null_call, call);
		str_len = print_str(&null_call);
	}
	else
	{
		s_elementik_data(&elementik, call);
		str_len += s_no_minus_w_precision(&elementik);
		str_len += s_minus_w_precision(&elementik);
		str_len += s_no_precision_func(&elementik);
	}
	return (str_len);
}

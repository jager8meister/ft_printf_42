/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:31:45 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:09:23 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_source.h"

void	c_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	if (do_print_call->c == 'c' && do_print_call->exit == 0)
	{
		callin->c = va_arg(*argp, int);
		print_char(callin, &do_print_call->str_len);
		do_print_call->exit++;
	}
}

void	xx_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	if (do_print_call->c == 'x' && do_print_call->exit == 0)
	{
		callin->unsigned_num = va_arg(*argp, unsigned int);
		print_combine_hex_with_flags(callin, 0, &do_print_call->str_len);
		do_print_call->exit++;
	}
	if (do_print_call->c == 'X' && do_print_call->exit == 0)
	{
		callin->unsigned_num = va_arg(*argp, unsigned int);
		print_combine_hex_with_flags(callin, 1, &do_print_call->str_len);
		do_print_call->exit++;
	}
}

void	percent_caller(t_print_call_element *do_print_call,
t_call_element *callin)
{
	if (do_print_call->c == '%' && do_print_call->exit == 0)
	{
		print_percentage(callin, &do_print_call->str_len);
		do_print_call->exit++;
	}
}

void	type_callers(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	callin_default_data(callin, do_print_call);
	di_caller(argp, do_print_call, callin);
	p_caller(argp, do_print_call, callin);
	s_caller(argp, do_print_call, callin);
	u_caller(argp, do_print_call, callin);
	c_caller(argp, do_print_call, callin);
	xx_caller(argp, do_print_call, callin);
	percent_caller(do_print_call, callin);
}

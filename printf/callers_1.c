/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:31:36 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:09:18 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_source.h"

void	di_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	if ((do_print_call->c == 'd' ||
	do_print_call->c == 'i') && (do_print_call->exit == 0))
	{
		callin->num = va_arg(*argp, int);
		print_number_with_flags(callin, &do_print_call->str_len);
		do_print_call->exit++;
	}
}

void	p_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	if (do_print_call->c == 'p' && (do_print_call->exit == 0))
	{
		callin->palka = va_arg(*argp, unsigned long long);
		print_p_with_flags(callin, &do_print_call->str_len);
		do_print_call->exit++;
	}
}

void	s_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	if (do_print_call->c == 's' && do_print_call->exit == 0)
	{
		callin->str = va_arg(*argp, char*);
		do_print_call->str_len = print_str(callin);
		do_print_call->exit++;
	}
}

void	u_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin)
{
	if (do_print_call->c == 'u' && do_print_call->exit == 0)
	{
		callin->unsigned_num = va_arg(*argp, unsigned int);
		print_unsigned_int_with_flags(callin, &do_print_call->str_len);
		do_print_call->exit++;
	}
}

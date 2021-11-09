/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:32:33 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:10:08 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_source.h"

void	do_prnt(register const char *fmt, va_list *argp, int *print_len)
{
	t_print_call_element	do_print_call;
	t_call_element			callin;

	*print_len = 0;
	while ((do_print_call.c = *fmt) != '\0')
	{
		if (do_print_call.c == '%')
		{
			print_call_data_default(&do_print_call);
			do_print_call.c = *++fmt;
			while (c_checker(do_print_call.c))
			{
				c_checker_core(&do_print_call, argp);
				do_print_call.c = *++fmt;
			}
			type_callers(argp, &do_print_call, &callin);
			if (do_print_call.exit == 1)
				do_print_call.c = *++fmt;
			*print_len += do_print_call.str_len;
		}
		else if (print_c_writer(do_print_call.c, print_len))
			fmt++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list	listp;
	int		this_printf_length;

	this_printf_length = 0;
	va_start(listp, fmt);
	do_prnt(fmt, &listp, &this_printf_length);
	va_end(listp);
	return (this_printf_length);
}

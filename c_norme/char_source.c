/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_source.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:41:05 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 22:57:11 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_source.h"

void	print_char(t_call_element *call, int *str_len)
{
	*str_len = 0;
	if (call->minus == 0)
	{
		call->width--;
		while (call->width > 0)
		{
			write(1, " ", 1);
			call->width--;
			*str_len += 1;
		}
	}
	write(1, &call->c, 1);
	*str_len += 1;
	if (call->minus != 0)
	{
		call->width--;
		while (call->width > 0)
		{
			write(1, " ", 1);
			call->width--;
			*str_len += 1;
		}
	}
}

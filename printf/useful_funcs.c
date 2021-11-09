/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:33:02 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:10:28 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_source.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *)s;
	sym = (char)c;
	while (*ptr && !(*ptr == sym))
		ptr++;
	return ((*ptr == sym) ? ptr : NULL);
}

int		c_checker(char c)
{
	char	*valid_args;

	valid_args = "0123456789-.*";
	return (c != 'd' && c != 'i' && c != '\0' && c != 'c'
			&& c != 's' && c != 'x' && c != 'X'
			&& c != 'p' && c != '%' && c != 'u'
			&& (ft_strchr(valid_args, c) != 0));
}

void	c_checker_core(t_print_call_element *do_print_call, va_list *argp)
{
	c_porcessor(do_print_call);
	star_processor(do_print_call, argp);
}

int		print_c_writer(char c, int *print_len)
{
	int result;

	result = 0;
	if (c != '%')
	{
		write(1, &c, 1);
		*print_len += 1;
		result++;
	}
	return (result);
}

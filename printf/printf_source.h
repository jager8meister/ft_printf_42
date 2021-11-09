/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_source.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:32:40 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:10:12 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SOURCE_H
# define PRINTF_SOURCE_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct	s_call_element
{
	int					num;
	char				c;
	unsigned int		unsigned_num;
	char				*str;
	unsigned long long	palka;
	int					precision;
	int					width;
	int					zero;
	int					minus;
	int					was_negative_precision;
}				t_call_element;

typedef	struct	s_print_call_element
{
	int					width;
	int					precision;
	int					zero;
	int					minus;
	int					dot;
	int					number;
	int					was_negative_precision;
	unsigned long long	palka;
	unsigned int		u_number;
	char				char_;
	int					str_len;
	char				*valid_args;
	int					exit;
	char				c;
	int					total_len;
	char				*fmt;
	va_list				*argp;
}				t_print_call_element;

void			di_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			p_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			s_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			u_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			c_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			xx_caller(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			percent_caller(t_print_call_element *do_print_call,
t_call_element *callin);
void			type_callers(va_list *argp,
t_print_call_element *do_print_call, t_call_element *callin);
void			print_call_data_default(t_print_call_element *print_call_elem);
void			callin_default_data(t_call_element *call_d,
t_print_call_element *p_call_d);
void			c_porcessor(t_print_call_element *call_elem);
void			star_processor(t_print_call_element *call_elem, va_list *argp);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
int				c_checker(char c);
void			c_checker_core(t_print_call_element *do_print_call,
va_list *argp);
int				print_c_writer(char c, int *print_len);
void			print_percentage(t_call_element *call, int *str_len);
void			print_char(t_call_element *call, int *str_len);
void			print_number_with_flags(t_call_element *call, int *str_len);
void			print_p_with_flags(t_call_element *call, int *str_len);
int				print_str(t_call_element *call);
void			print_unsigned_int_with_flags(t_call_element *call,
int *str_len);
void			print_combine_hex_with_flags(t_call_element *call,
int size_of_symbols, int *str_len);
#endif

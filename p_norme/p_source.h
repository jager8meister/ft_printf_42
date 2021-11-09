/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_source.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:05:58 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:08:23 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SOURCE_H
# define P_SOURCE_H

# include "../printf/printf_source.h"

typedef	struct	s_p_element
{
	unsigned long long	num;
	unsigned long long	power;
	int					was_printed;
	char				*all_hex_digits;
	int					precision;
	int					width;
	int					zero;
	int					minus;
	int					was_negative_precision;
	int					size;
}				t_p_element;

void			p_n_minus_w_precision(t_p_element *elem_data, int *str_len);
void			p_n_minus_n_precision_core(t_p_element *elem_data,
int *str_len);
void			p_n_minus_n_precision(t_p_element *elem_data, int *str_len);
void			p_default_data(t_p_element *elem_data, t_call_element *call);
void			p_checkings(t_p_element *elem_data);
void			p_power_finder(t_p_element *elem_data);
void			p_minus_w_precision(t_p_element *elem_data, int *str_len);
void			p_minus_no_precision(t_p_element *elem_data, int *str_len);
void			p_precision_zeros(t_p_element *elem_data, int *str_len);
void			p_zero_check(t_p_element *elem_data, int *str_len);
void			p_writer(t_p_element *elem_data, int *str_len);
int				p_size_of_digit(unsigned long long num);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_source.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:07:49 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:11:53 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_SOURCE_H
# define U_SOURCE_H

# include "../printf/printf_source.h"

typedef	struct	s_unsigned_int_element
{
	int				precision;
	int				width;
	unsigned int	num;
	int				zero;
	int				minus;
	int				was_negative_precision;
	int				size;
	long long		power;
}				t_unsigned_int_element;

int				u_minus_with_precision(t_unsigned_int_element *elem_data);
int				u_minus_without_precision(t_unsigned_int_element *elem_data);
int				u_no_minus_with_precision(t_unsigned_int_element *elem_data);
int				u_no_minus_no_precision(t_unsigned_int_element *e_d);
void			u_precision_check(t_unsigned_int_element *elem_data);
int				u_precision_zeros(t_unsigned_int_element *elem_data);
void			u_power_finder(t_unsigned_int_element *elem_data);
int				unsigned_int_number_writer(t_unsigned_int_element *elem_data);

#endif

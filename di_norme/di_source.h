/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_source.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:29:10 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:06:08 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DI_SOURCE_H
# define DI_SOURCE_H
# include "../printf/printf_source.h"

typedef	struct	s_di_element
{
	int			precision;
	int			width;
	int			num;
	int			zero;
	int			minus;
	int			was_negative_precision;
	int			size;
	int			negative;
	int			was_printed;
	long long	l_num;
	long long	power;
}				t_di_element;

int				di_size_of_digit(int num);
long long		di_abs_long(long long j);
int				di_size_of_digit(int num);
void			di_precision_checking(t_di_element *elem_data);
int				di_minus_check(t_di_element *elem_data);
long long		di_power_finder(long long l_num);
int				di_no_minus_with_precision(t_di_element *elem_data);
int				di_no_minus_no_precision_diff_src(int diff, int zero);
int				di_no_minus_no_precision(t_di_element *elem_data);
int				di_minus_without_precision(t_di_element *elem_data);
int				di_minus_with_precision(t_di_element *elem_data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_source.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:58:48 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:13:42 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XX_SOURCE_H
# define XX_SOURCE_H

# include "../printf/printf_source.h"

typedef	struct	s_xx_element
{
	int				precision;
	int				width;
	int				minus;
	int				size;
	int				zero;
	int				was_negative_precision;
	unsigned int	num;
	long long		power;
	int				negative;
	int				was_printed;
	char			*all_hex_digits;
}				t_xx_element;

int				xx_minus_w_precision(t_xx_element *elem_data);
int				xx_minus_no_precision(t_xx_element *elem_data);
int				xx_no_minus_w_precision(t_xx_element *elem_data);
int				xx_no_minus_no_precision(t_xx_element *elem_data);
void			xx_precision_checking(t_xx_element *elem_data);
int				xx_precision_zeros(t_xx_element *elem_data);
int				xx_size_of_digit(unsigned int num);
void			xx_power_finder(t_xx_element *elem_data);
int				xx_hex_number_writer(t_xx_element *elem_data);
#endif

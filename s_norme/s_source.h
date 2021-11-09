/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_source.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:02:32 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:11:03 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SOURCE_H
# define S_SOURCE_H

# include "../printf/printf_source.h"

typedef struct	s_str_element
{
	int				precision;
	int				width;
	int				minus;
	int				size;
	char			*str;
}				t_str_element;

int				s_no_minus_w_precision(t_str_element *e_d);
int				s_minus_w_precision(t_str_element *elem_data);
int				s_no_precision_func(t_str_element *elem_data);
int				s_size_of_str(char *str);
void			s_space_writer(int *diff, int *str_len);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_source.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:39:43 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:15:30 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERCENT_SOURCE_H
# define PERCENT_SOURCE_H

# include "../printf/printf_source.h"

typedef	struct			s_percent_element
{
	int					precision;
	int					width;
	int					zero;
	int					minus;
	int					size;
}						t_percent_element;

#endif

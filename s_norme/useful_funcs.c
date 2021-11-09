/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:41:44 by tsidney           #+#    #+#             */
/*   Updated: 2021/01/18 23:11:10 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_source.h"

int		s_size_of_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	s_space_writer(int *diff, int *str_len)
{
	while (*diff > 0)
	{
		write(1, " ", 1);
		*diff -= 1;
		*str_len += 1;
	}
}

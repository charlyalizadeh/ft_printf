/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:44:09 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 15:23:39 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/precision.h"

static void	init_printf_precision(t_printf_precision *precision)
{
	precision->min_print = -1;
	precision->in_format = FALSE;
}

int	get_printf_precision(const char *format, t_printf_precision *precision)
{
	int	offset;

	init_printf_precision(precision);
	if (*format != '.')
		return (0);
	format++;
	offset = 1;
	if (*format == '*')
	{
		precision->in_format = TRUE;
		return (2);
	}
	else if (*format >= '0' && *format <= '9')
	{
		precision->min_print = 0;
		while (*format >= 0 && *format <= '9')
		{
			precision->min_print = precision->min_print * 10 + (*format++
					- '0');
			offset++;
		}
	}
	else
		precision->min_print = 0;
	return (offset);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:46 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 16:18:22 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/width.h"

static void	init_printf_width(t_printf_width *width)
{
	width->min_print = -1;
	width->in_format = FALSE;
}

int	get_printf_width(const char *format, t_printf_width *width)
{
	int	offset;

	init_printf_width(width);
	offset = 0;
	if (*format == '*')
	{
		width->in_format = TRUE;
		return (1);
	}
	if (*format >= '0' && *format <= '9')
	{
		width->min_print = 0;
		while (*format >= '0' && *format <= '9')
		{
			width->min_print = width->min_print * 10 + (*format++ - '0');
			offset++;
		}
	}
	return (offset);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:54:10 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 15:59:28 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int	get_format_specifier(const char *format, t_format_specifier *fspec)
{
	int	offset;

	offset = 1;
	offset += get_printf_flags(format + offset, &fspec->flags);
	offset += get_printf_width(format + offset, &fspec->width);
	offset += get_printf_precision(format + offset, &fspec->precision);
	fspec->specifier = *(format + offset);
	if ((fspec->specifier == 'd' || fspec->specifier == 'i'
			|| fspec->specifier == 'u' || fspec->specifier == 'o'
			|| fspec->specifier == 'x' || fspec->specifier == 'X')
		&& (fspec->precision.in_format || fspec->precision.min_print != -1))
	{
		fspec->flags.left_pad_0 = FALSE;
	}
	offset++;
	return (offset);
}

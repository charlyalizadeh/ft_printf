/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:39:04 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 15:58:18 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/flags.h"

static int	check_is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

static void	init_flags(t_printf_flags *flags)
{
	flags->left_justify = FALSE;
	flags->force_sign = 0;
	flags->dec_point = FALSE;
	flags->left_pad_0 = FALSE;
}

int	get_printf_flags(const char *format, t_printf_flags *flags)
{
	int	offset;

	offset = 0;
	if (!flags)
		return (offset);
	init_flags(flags);
	while (check_is_flag(*format))
	{
		if (*format == '-')
		{
			flags->left_justify = TRUE;
			flags->left_pad_0 = FALSE;
		}
		else if (*format == '+')
			flags->force_sign = '+';
		else if (*format == ' ' && flags->force_sign == 0)
			flags->force_sign = ' ';
		else if (*format == '#')
			flags->dec_point = TRUE;
		else if (*format == '0' && !flags->left_justify)
			flags->left_pad_0 = TRUE;
		format++;
		offset++;
	}
	return (offset);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:54 by charly            #+#    #+#             */
/*   Updated: 2023/11/23 15:46:45 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	apply_width(t_format_specifier *fspec, char **print_val)
{
	size_t	print_val_len;
	char	pad_char[2];

	pad_char[0] = ' ';
	pad_char[1] = '\0';
	if (fspec->flags.left_pad_0)
	{
		pad_char[0] = '0';
		pad_char[1] = '\0';
	}
	print_val_len = ft_strlen(*print_val);
	if ((long)print_val_len < (long)fspec->width.min_print)
	{
		if (fspec->flags.left_justify && !fspec->flags.left_pad_0)
			ft_strninsrtend(print_val, pad_char, (long)fspec->width.min_print
				- (long)print_val_len);
		else
			ft_strninsrtstart(print_val, pad_char, (long)fspec->width.min_print
				- (long)print_val_len);
	}
}

int	specifier_to_str(const char *format, t_format_specifier *fspec,
		va_list args, char **out)
{
	int	offset;

	offset = get_format_specifier(format, fspec);
	if (fspec->width.in_format)
		fspec->width.min_print = va_arg(args, int);
	if (fspec->precision.in_format)
		fspec->precision.min_print = va_arg(args, int);
	if (check_specifier_sint(fspec->specifier))
		*out = format_int(fspec, va_arg(args, int));
	else if (check_specifier_uint(fspec->specifier))
		*out = format_int(fspec, va_arg(args, unsigned int));
	else if (check_specifier_dec(fspec->specifier))
		*out = format_dec(fspec, va_arg(args, double));
	else if (fspec->specifier == 'c')
		*out = format_char(va_arg(args, int));
	else if (fspec->specifier == 's')
		*out = format_str(fspec, va_arg(args, char *));
	else if (fspec->specifier == 'p')
		*out = format_pointer(va_arg(args, void *));
	apply_width(fspec, out);
	return (offset);
}

int	ft_printf_it(const char **format, va_list args)
{
	int					nchar_print;
	char				*print_val;
	t_format_specifier	fspec;

	nchar_print = 0;
	if ((**format == '%' && *(*format + 1) == '%') || **format != '%')
	{
		if (**format == '%' && *(*format + 1) == '%')
			(*format)++;
		ft_putchar_fd(**format, 1);
		nchar_print = 1;
		(*format)++;
	}
	else if (**format == '%')
	{
		*format += specifier_to_str(*format, &fspec, args, &print_val);
		if (fspec.specifier == 'c' && nchar_print == 0)
			nchar_print = 1;
		else
			nchar_print = ft_strlen(print_val);
		write(1, print_val, nchar_print);
		free(print_val);
	}
	return (nchar_print);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, format);
	while (*format)
		size += ft_printf_it(&format, args);
	va_end(args);
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:18:16 by charly            #+#    #+#             */
/*   Updated: 2023/11/23 14:49:28 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "bool.h"
# include "check_specifier.h"
# include "format_char.h"
# include "format_dec.h"
# include "format_int.h"
# include "format_pointer.h"
# include "format_str.h"
# include <stdarg.h>

int	specifier_to_str(const char *format, t_format_specifier *fspec,
		va_list args, char **out);
int	ft_printf_it(const char **format, va_list args);
int	ft_printf(const char *format, ...);

#endif

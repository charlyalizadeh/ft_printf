/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:53:49 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 15:43:39 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_SPECIFIER_H
# define FORMAT_SPECIFIER_H

# include "bool.h"
# include "flags.h"
# include "libft.h"
# include "precision.h"
# include "width.h"

typedef struct s_format_specifier
{
	t_printf_flags		flags;
	t_printf_width		width;
	t_printf_precision	precision;
	char				specifier;
}						t_format_specifier;

int						check_specifier_int(char specifier);
int						check_specifier_sint(char specifier);
int						check_specifier_uint(char specifier);
int						check_specifier_number(char specifier);
int						get_format_specifier(const char *format,
							t_format_specifier *fspec);

#endif

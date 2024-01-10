/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:39:01 by charly            #+#    #+#             */
/*   Updated: 2023/11/21 15:39:52 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "bool.h"

typedef struct s_printf_flags
{
	int		left_justify;
	char	force_sign;
	int		dec_point;
	int		left_pad_0;
}			t_printf_flags;

int			get_printf_flags(const char *format, t_printf_flags *flags);

#endif

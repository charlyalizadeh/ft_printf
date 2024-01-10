/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:43:52 by charly            #+#    #+#             */
/*   Updated: 2023/11/21 15:40:17 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECISION_H
# define PRECISION_H

# include "bool.h"

typedef struct s_printf_precision
{
	int	min_print;
	int	in_format;
}		t_printf_precision;

int		get_printf_precision(const char *format, t_printf_precision *precision);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:48:04 by charly            #+#    #+#             */
/*   Updated: 2023/11/21 15:40:40 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDTH_H
# define WIDTH_H

# include "bool.h"

typedef struct s_printf_width
{
	int	min_print;
	int	in_format;
}		t_printf_width;

int		get_printf_width(const char *format, t_printf_width *width);

#endif

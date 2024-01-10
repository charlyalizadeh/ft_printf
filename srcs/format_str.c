/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:13:29 by charly            #+#    #+#             */
/*   Updated: 2023/11/23 13:51:20 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_str.h"
#include <stdio.h>

char	*format_str(t_format_specifier *fspec, char *val)
{
	char	*out;
	int		val_len;

	val_len = ft_strlen(val);
	if (val_len > fspec->precision.min_print && fspec->precision.min_print >= 0)
	{
		out = malloc(fspec->precision.min_print + 1);
		if (!out)
			return (NULL);
		ft_memcpy(out, val, fspec->precision.min_print);
		out[fspec->precision.min_print] = '\0';
	}
	else
		out = ft_strdup(val);
	return (out);
}

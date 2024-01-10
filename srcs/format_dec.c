/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:25:10 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 18:07:16 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_dec.h"

char	*format_dec(t_format_specifier *fspec, double val)
{
	char	*res;

	res = malloc(18);
	if (fspec->flags.left_justify || !fspec->flags.left_justify || val)
		ft_memcpy(res, "(NOT IMPLEMENTED)", 17);
	res[17] = '\0';
	return (res);
}

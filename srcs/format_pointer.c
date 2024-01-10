/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:25:04 by charly            #+#    #+#             */
/*   Updated: 2023/11/23 15:39:34 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_pointer.h"
#include <stdio.h>

char	*format_pointer(void *val)
{
	uintptr_t	adress;
	char		*adress_str;

	adress = (uintptr_t)val;
	if (adress == 0)
	{
		adress_str = malloc(6);
		ft_memcpy(adress_str, "(nil)", 6);
		return (adress_str);
	}
	adress_str = ft_uitoa_base(adress, "0123456789abcdef");
	ft_strinsrtstart(&adress_str, "0x");
	return (adress_str);
}

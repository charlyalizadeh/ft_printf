/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:44:08 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 16:13:29 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_specifier.h"

int	check_specifier_int(char specifier)
{
	return (specifier == 'd' || specifier == 'i' || specifier == 'u'
		|| specifier == 'o' || specifier == 'x' || specifier == 'X');
}

int	check_specifier_sint(char specifier)
{
	return (specifier == 'd' || specifier == 'i');
}

int	check_specifier_uint(char specifier)
{
	return (specifier == 'u' || specifier == 'o' || specifier == 'x'
		|| specifier == 'X');
}

int	check_specifier_dec(char specifier)
{
	return (specifier == 'f' || specifier == 'e' || specifier == 'E');
}

int	check_specifier_number(char specifier)
{
	return (check_specifier_int(specifier) || check_specifier_dec(specifier));
}

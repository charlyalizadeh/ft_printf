/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:25:31 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 15:22:35 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_int.h"
#include <stdio.h>

static char	*get_base(char specifier)
{
	char	*base;

	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
	{
		base = malloc(11);
		ft_strlcpy(base, "0123456789", 11);
	}
	else if (specifier == 'o')
	{
		base = malloc(9);
		ft_strlcpy(base, "01234567", 9);
	}
	else if (specifier == 'x')
	{
		base = malloc(17);
		ft_strlcpy(base, "0123456789abcdef", 17);
	}
	else if (specifier == 'X')
	{
		base = malloc(17);
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	}
	return (base);
}

static char	*get_int_str(char specifier, long val)
{
	char	*int_str;
	char	*base;

	base = get_base(specifier);
	if (val < 0)
		int_str = ft_itoa_base(-val, base);
	else
		int_str = ft_itoa_base(val, base);
	free(base);
	return (int_str);
}

static void	add_sign(t_format_specifier *fspec, long val, char **int_str)
{
	if (val < 0)
		ft_strinsrtstart(int_str, "-");
	if ((fspec->flags.force_sign == '+' && val > 0))
		ft_strinsrtstart(int_str, "+");
}

static void	add_prefix(char specifier, char **int_str)
{
	if (specifier == 'o' && (*int_str)[0] != '0')
		ft_strinsrtstart(int_str, "0");
	else if (specifier == 'x')
		ft_strinsrtstart(int_str, "0x");
	else if (specifier == 'X')
		ft_strinsrtstart(int_str, "0X");
}

char	*format_int(t_format_specifier *fspec, long val)
{
	char	*int_str;
	size_t	int_str_len;

	int_str = get_int_str(fspec->specifier, val);
	int_str_len = ft_strlen(int_str);
	if (fspec->precision.min_print == 0 && val == 0)
		int_str[0] = '\0';
	if (fspec->precision.min_print != -1
		&& fspec->precision.min_print > (int)int_str_len)
		ft_strninsrtstart(&int_str, "0", fspec->precision.min_print
			- int_str_len);
	add_sign(fspec, val, &int_str);
	if (fspec->flags.force_sign == ' ' && val >= 0)
		ft_strinsrtstart(&int_str, " ");
	if (fspec->flags.dec_point)
		add_prefix(fspec->specifier, &int_str);
	return (int_str);
}

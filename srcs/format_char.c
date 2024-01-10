/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:33:46 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 18:04:39 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_char.h"

char	*format_char(int val)
{
	char	*char_str;

	char_str = malloc(2);
	char_str[0] = (char)val;
	char_str[1] = '\0';
	return (char_str);
}

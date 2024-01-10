/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:13:14 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 18:18:00 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_STR_H
# define FORMAT_STR_H

# include "format_specifier.h"

char	*format_str(t_format_specifier *fspec, char *val);

#endif

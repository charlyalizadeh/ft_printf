/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charly </var/spool/mail/charly>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:24:08 by charly            #+#    #+#             */
/*   Updated: 2023/11/22 17:38:26 by charly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_INT_H
# define FORMAT_INT_H

# include "bool.h"
# include "format_specifier.h"

char	*format_int(t_format_specifier *fspec, long val);

#endif

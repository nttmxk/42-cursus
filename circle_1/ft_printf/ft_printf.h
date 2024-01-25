/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:31:13 by jinoh             #+#    #+#             */
/*   Updated: 2022/01/06 17:31:14 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

int			ft_printf(const char *fmt, ...);
void		ft_printf_parse(char c, va_list *ap, int *cnt);

void		ft_printf_char(char c, int *cnt);
void		ft_printf_str(char *str, int *cnt);
void		ft_printf_int(int num, int *cnt);
void		ft_printf_uint(unsigned int num, int *cnt);
void		ft_printf_hexa(unsigned long long nbr, int mode, int *cnt);

char		*ft_itoa_u(unsigned int n);

#endif

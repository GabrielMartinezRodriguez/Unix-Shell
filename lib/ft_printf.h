/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tixtex <tixtex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:19:23 by uherrero          #+#    #+#             */
/*   Updated: 2020/02/24 18:51:41 by tixtex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_sstr
{
	int				len;
	char			*i;
}					t_sstr;

typedef struct		s_flags
{
	int				*neg;
	int				*zero;
	int				*point;
	int				*width;
}					t_flags;

typedef struct		s_print
{
	int				char_print;
	const char		*str;
	struct s_flags	*flags;
	va_list			ap;
}					t_print;


int					ft_printf(const char *str, ...);
void				ft_flag_set_handler(t_print *print);
void				ft_format_select_handler(t_print *print);
void				ft_print_int(t_print *print);
void				ft_putchar_repeat(t_print *print, int num, char c);
void				ft_print_char(t_print *print);
void				ft_print_string(t_print *print);
void				ft_print_unsigned(t_print *print);
void				ft_print_hex(t_print *print);
void				ft_print_pointer(t_print *print);
void				ft_print_percent(t_print *print);
void				ft_print_sp(t_print *print, int flag, t_sstr str);
void				ft_print_zeros(t_print *print, t_sstr str);
void				ft_incrust_zeros(t_print *print, t_sstr *str);
void				ft_incrust_zeros_neg(t_sstr *str, char *zs_aux,
					char *str_aux);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:44:46 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 10:14:39 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define EMPTY ""
# define TYPE "cspdiuxX%"

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
}				t_info;

int				ft_printf(const char *str, ...);
int				parse_str(char *str, va_list ap);
void			check_flags(int c, t_info *info, va_list ap);
void			check_width_and_prec(int c, t_info *info, va_list ap);
int				parse_format(va_list ap, t_info *info);

int				print_char(int c, t_info *info);
int				print_str(char *str, t_info *info);
int				print_num(unsigned long long num, t_info *info);
int				put_minus(char **buf, t_info *info);
int				put_prec_str(unsigned long long num, char **buf, t_info *info);
int				put_width_str(char **buf, t_info *info);

int				put_char(int c);
int				put_str(char *str);
void			init_info(t_info *info);
int				check_specifier(char *str, int idx);
char			*set_base(t_info *info);
int				get_num_len(unsigned long long num, t_info *info);

#endif
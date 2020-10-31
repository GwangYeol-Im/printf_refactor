/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:43:55 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 23:18:41 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_format(va_list ap, t_info *info)
{
	int		ret;

	ret = 0;
	if (info->type == '%')
		ret = print_char('%', info);
	else if (info->type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (info->type == 's')
		ret = print_str(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		ret = print_num(va_arg(ap, int), info);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		ret = print_num(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		ret = print_num(va_arg(ap, unsigned long long), info);
	return (ret);
}

void		check_width_and_prec(int c, t_info *info, va_list ap)
{
	if (c == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
	else
	{
		if (info->prec == -1)
			info->width = info->width * 10 + (c - '0');
		else
			info->prec = info->prec * 10 + (c - '0');
	}
}

void		check_flags(int c, t_info *info, va_list ap)
{
	if (c == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (c == '-')
		info->minus = 1;
	else if (c == '.')
		info->prec = 0;
	else if (ft_isdigit(c) || c == '*')
		check_width_and_prec(c, info, ap);
}

void		parse_str(char *str, va_list ap, int *ret)
{
	int		i;
	t_info	*info;

	i = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return ;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			*ret += put_char(str[i++]);
		if (!str[i])
			break ;
		init_info(info);
		while (str[++i] && !check_specifier(str, i))
			check_flags(str[i], info, ap);
		if (!str[i])
			break ;
		info->type = str[i];
		if ((info->minus == 1 || info->prec > -1) && info->type != '%')
			info->zero = 0;
		*ret += parse_format(ap, info);
		i++;
	}
	free(info);
}

int			ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	parse_str((char *)str, ap, &ret);
	va_end(ap);
	return (ret);
}

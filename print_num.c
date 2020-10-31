/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:22:49 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 22:59:54 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_minus(char **buf, t_info *info)
{
	int		len;

	len = 0;
	if ((info->type == 'i' || info->type == 'd') &&
					info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len = 1;
	}
	return (len);
}

int			put_prec_str(unsigned long long num, char **buf, t_info *info)
{
	int		i;
	int		buf_len;

	buf_len = get_num_len(num, info);
	if (info->type != 'p' && info->prec > buf_len)
		buf_len = info->prec;
	if (!(*buf = (char *)malloc(sizeof(char) * (buf_len + 1))))
		return (0);
	(*buf)[buf_len] = '\0';
	i = 0;
	while (i < buf_len)
		(*buf)[i++] = '0';
	i = 1;
	while (num)
	{
		(*buf)[buf_len - i++] = set_base(info)[num % info->nbr_base];
		num /= info->nbr_base;
	}
	return (buf_len);
}

int			put_width_str(char **buf, t_info *info)
{
	int		i;
	int		len;
	char	*prefix;

	len = ft_strlen(*buf);
	if (info->width <= len && len > 0)
		return (len);
	if (!(prefix = (char *)malloc(sizeof(char) * (info->width - len + 1))))
		return (0);
	i = 0;
	while (i < info->width - len)
	{
		if (info->zero == 1)
			prefix[i++] = '0';
		else
			prefix[i++] = ' ';
	}
	prefix[i] = '\0';
	if (info->minus == 1)
		*buf = ft_strjoin(*buf, prefix, 3);
	else
		*buf = ft_strjoin(prefix, *buf, 3);
	return (info->width);
}

int			put_minus2(char **buf, t_info *info, int buf_len)
{
	int		len;

	len = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len = 1;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (len);
}

int			print_num(unsigned long long num, t_info *info)
{
	int		ret;
	int		buf_len;
	char	*buf;

	ret = 0;
	if (info->type == 'p' || info->type == 'x' || info->type == 'X')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)num < 0)
	{
		info->nbr_sign = -1;
		num *= -1;
	}
	buf_len = put_prec_str(num, &buf, info);
	buf_len += put_minus(&buf, info);
	if (info->type == 'p')
		buf = ft_strjoin("0x", buf, 2);
	ret = put_width_str(&buf, info);
	ret += put_minus2(&buf, info, buf_len);
	write(1, buf, ret);
	free(buf);
	return (ret);
}

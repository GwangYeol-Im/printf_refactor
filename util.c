/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:51:47 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 22:36:47 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int			put_str(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int			check_specifier(char *str, int idx)
{
	int		i;

	i = 0;
	while (TYPE[i])
		if (TYPE[i++] == str[idx])
			return (1);
	return (0);
}

void		init_info(t_info *info)
{
	info->minus = 0;
	info->width = 0;
	info->zero = 0;
	info->prec = -1;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

char		*set_base(t_info *info)
{
	if (info->nbr_base == 16)
	{
		if (info->type == 'X')
			return ("0123456789ABCDEF");
		else
			return ("0123456789abcdef");
	}
	else
		return ("0123456789");
}

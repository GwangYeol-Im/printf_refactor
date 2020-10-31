/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imgwang-yeol <imgwang-yeol@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:02:25 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 22:21:14 by imgwang-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(int c, t_info *info)
{
	int		i;

	if (info->zero == 1 && info->minus == 1)
		info->zero = 0;
	if (info->width == 0)
		return (put_char(c));
	if (info->minus == 1)
		put_char(c);
	i = 0;
	while (i < info->width - 1)
	{
		if (info->zero == 1)
			put_char('0');
		else
			put_char(' ');
		i++;
	}
	if (info->minus == 0)
		put_char(c);
	return (info->width);
}

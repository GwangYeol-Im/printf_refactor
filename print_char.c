/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:02:25 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 15:12:19 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(int c, t_info *info)
{
	int		i;

	if (info->width == 0)
		return (put_char(c));
	if (info->minus == 1)
		put_char(c);
	i = 0;
	while (i < info->width - 1)
	{
		put_char(' ');
		i++;
	}
	if (info->minus == 0)
		put_char(c);
	return (info->width);
}

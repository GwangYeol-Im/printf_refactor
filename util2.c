/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:42:04 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 22:35:48 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_num_len(unsigned long long num, t_info *info)
{
	int		len;

	if (num == 0)
		return (info->prec == 0 ? 0 : 1);
	len = 0;
	while (num)
	{
		len++;
		num /= info->nbr_base;
	}
	return (len);
}

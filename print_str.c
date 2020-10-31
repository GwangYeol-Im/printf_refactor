/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:08:11 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 22:59:47 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_str(char *str, t_info *info)
{
	int		len;
	int		ret;
	char	*buf;

	ret = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (info->prec > -1)
		len = info->prec < len ? info->prec : len;
	buf = ft_substr(str, 0, len);
	if (info->minus == 1)
		ret += put_str(buf);
	while (info->width-- > len)
		ret += put_char(' ');
	if (info->minus == 0)
		ret += put_str(buf);
	free(buf);
	return (ret);
}

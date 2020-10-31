/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:08:11 by gim               #+#    #+#             */
/*   Updated: 2020/10/31 15:55:35 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*get_null_str(int len)
{
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	buf = "(null)";
	return (buf);
}

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
	buf = str ? ft_substr(str, 0, len) : get_null_str(len);
	if (info->minus == 1)
		ret += put_str(buf);
	while (info->width-- > len)
		ret += put_char(' ');
	if (info->minus == 0)
		ret += put_str(buf);
	free(buf);
	return (ret);
}

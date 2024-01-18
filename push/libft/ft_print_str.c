/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:57:29 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:57:31 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str(va_list args, int *print)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*print += 6;
		return ;
	}
	while (*str)
	{
		write(1, &*str++, 1);
		*print += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:56:17 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:56:19 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_spaces(const char *nptr)
{
	if (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == ' ')
		return (1);
	return (0);
}

static int	check_number(const char *nptr)
{
	if (*nptr >= '0' && *nptr <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	result;

	result = 0;
	signal = 1;
	i = 0;
	while (check_spaces(&nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (check_number(&nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (signal * result);
}

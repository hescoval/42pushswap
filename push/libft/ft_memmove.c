/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:57:18 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:57:19 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*mdest;
	char	*msrc;

	mdest = (char *)dest;
	msrc = (char *)src;
	if (src > dest)
		ft_memcpy(dest, src, n);
	if (dest > src)
	{
		while (n > 0)
		{
			mdest[n - 1] = msrc[n - 1];
			n--;
		}
	}
	return (mdest);
}

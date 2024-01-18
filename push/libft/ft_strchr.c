/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:55:38 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s)
	{
		while (*s)
		{
			if (*s == (const char)c)
			{
				return ((char *)s);
			}
			s++;
		}
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}

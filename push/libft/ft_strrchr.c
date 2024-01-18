/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:01 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:55:03 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	final;

	final = ft_strlen(s);
	i = final;
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == 0)
		return ((char *)&s[final]);
	return (NULL);
}

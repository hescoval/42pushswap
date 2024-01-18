/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:31 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:55:33 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	str_size;
	size_t	i;

	i = 0;
	str_size = ft_strlen(s);
	ptr = ft_calloc(str_size + 1, 1);
	if (!ptr)
		return (NULL);
	while (i <= str_size)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:22 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:55:23 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ptr = ft_calloc(s1_size + s2_size + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < s1_size)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_size)
	{
		ptr[s1_size] = s2[i];
		s1_size++;
		i++;
	}
	ptr[s1_size] = '\0';
	return (ptr);
}

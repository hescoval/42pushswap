/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:56:42 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:56:44 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node_helper;

	node_helper = *lst;
	if (node_helper == NULL)
	{
		*lst = new;
		return ;
	}
	while (node_helper->next)
		node_helper = node_helper->next;
	node_helper->next = new;
}

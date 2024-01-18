/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:56:47 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:56:49 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_helper;
	t_list	*node_free;

	node_helper = *lst;
	while (node_helper)
	{
		del(node_helper->content);
		node_free = node_helper;
		node_helper = node_helper->next;
		free(node_free);
	}
	*lst = NULL;
}

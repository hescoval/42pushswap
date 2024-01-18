/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:52:41 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:52:41 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **sa, t_stack **sb, char *str)
{
	str = NULL;
	rrx(sa, str);
	rrx(sb, str);
	str = "rrr";
	ft_putendl_fd(str, 1);
}

void	rr(t_stack **sa, t_stack **sb, char *str)
{
	str = NULL;
	rx(sa, str);
	rx(sb, str);
	str = "rr";
	ft_putendl_fd(str, 1);
}

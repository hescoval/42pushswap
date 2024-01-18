/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:26 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:53:26 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *sa)
{
	t_stack	*min_node;
	int		min;

	min = sa->number;
	while (sa)
	{
		if (sa->number <= min)
		{
			min_node = sa;
			min = sa->number;
		}
		sa = sa->next;
	}
	return (min_node);
}

void	set_target_b(t_stack *sa, t_stack *sb)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_index;

	while (sb)
	{
		best_index = LONG_MAX;
		current_a = sa;
		while (current_a)
		{
			if (current_a->number > sb->number
				&& current_a->number < best_index)
			{
				best_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			sb->target_node = find_min(sa);
		else
			sb->target_node = target_node;
		sb = sb->next;
	}
}

void	move_b_to_a(t_stack **sa, t_stack **sb)
{
	prep_for_push(sa, (*sb)->target_node, 'a');
	do_op(sb, sa, PA);
}

void	min_on_top(t_stack **sa)
{
	while ((*sa)->number != find_min(*sa)->number)
	{
		if (find_min(*sa)->above_median)
			do_op(sa, NULL, RA);
		else
			do_op(sa, NULL, RRA);
	}
}

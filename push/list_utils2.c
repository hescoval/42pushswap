/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:57:49 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:57:51 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **sa, t_stack **sb)
{
	int	len_a;

	len_a = stack_len(*sa);
	if (len_a-- > 3 && !is_sorted(*sa))
		do_op(sa, sb, PB);
	if (len_a-- > 3 && !is_sorted(*sa))
		do_op(sa, sb, PB);
	while (len_a-- > 3 && !is_sorted(*sa))
	{
		init_nodes_a(*sa, *sb);
		move_a_to_b(sa, sb);
	}
	sort_three(sa);
	while (*sb)
	{
		init_nodes_b(*sa, *sb);
		move_b_to_a(sa, sb);
	}
	current_index(*sa);
	min_on_top(sa);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack *sa, t_stack *sb)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_index;

	while (sa)
	{
		best_index = LONG_MIN;
		current_b = sb;
		while (current_b)
		{
			if (current_b->number < sa->number
				&& current_b->number > best_index)
			{
				best_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			sa->target_node = find_biggest_node(sb);
		else
			sa->target_node = target_node;
		sa = sa->next;
	}
}

void	check_cost_a(t_stack *sa, t_stack *sb)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(sa);
	len_b = stack_len(sb);
	while (sa)
	{
		sa->push_cost = sa->index;
		if (!(sa->above_median))
			sa->push_cost = len_a - (sa->index);
		if (sa->target_node->above_median)
			sa->push_cost += sa->target_node->index;
		else
			sa->push_cost += len_b - (sa->target_node->index);
		sa = sa->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

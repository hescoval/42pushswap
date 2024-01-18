/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:49 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:53:51 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(t_stack *popped)
{
	while (popped)
		popped = popped->next;
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*find_biggest_node(t_stack *stack)
{
	int		big_number;
	t_stack	*big_node;

	big_number = stack->number;
	while (stack)
	{
		if (stack->number >= big_number)
		{
			big_node = stack;
			big_number = stack->number;
		}
		stack = stack->next;
	}
	return (big_node);
}

void	sort_three(t_stack **stack)
{
	t_stack	*last_node;

	last_node = find_last_node(*stack);
	if ((*stack)->next->number > (*stack)->number
		&& (*stack)->next->number > last_node->number)
		do_op(stack, NULL, RRA);
	if (is_sorted(*stack))
		return ;
	if ((*stack)->number > last_node->number)
		do_op(stack, NULL, RA);
	if (is_sorted(*stack))
		return ;
	if ((*stack)->number > (*stack)->next->number)
		do_op(stack, NULL, SA);
	if (is_sorted(*stack))
		return ;
}

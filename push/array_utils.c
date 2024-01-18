/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:00 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:54:03 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_array(char **argv, int *n_array)
{
	int	i;
	int	j;
	int	index;

	if (!n_array)
		return (0);
	i = 1;
	index = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\t' 
			|| argv[i][j] == '\n')
				j++;
			if (argv[i][j])
				n_array[index++] = ft_atoi(&argv[i][j]);
			while (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
				j++;
		}
		i++;
	}
	return (n_array);
}

void	check_duplicates(int *n_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (n_array[i] == n_array[j])
			{
				free(n_array);
				print_error();
			}
			j++;
		}
		i++;
	}
	return ;
}

void	stack_fill(t_stack **stack, int *n_array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		append_nodes(stack, n_array[i]);
		i++;
	}
}

void	append_nodes(t_stack **stack, int number)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->number = number;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*find_last_node(t_stack *stack)
{
	t_stack	*last_node;

	while (stack->next)
		stack = stack->next;
	last_node = stack;
	return (last_node);
}

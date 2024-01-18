/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:41 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:53:42 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	free_memory(t_stack *sa, t_stack *sb, int *n_array)
{
	t_stack	*aux;

	aux = sa;
	while (aux)
	{
		aux = sa->next;
		free(sa);
		sa = aux;
	}
	aux = sb;
	while (aux)
	{
		aux = sb->next;
		free(sb);
		sb = aux;
	}
	free(n_array);
}

void	init_nodes_a(t_stack *sa, t_stack *sb)
{
	current_index(sa);
	current_index(sb);
	set_target_a(sa, sb);
	check_cost_a(sa, sb);
	set_cheapest(sa);
}

void	init_nodes_b(t_stack *sa, t_stack *sb)
{
	current_index(sa);
	current_index(sb);
	set_target_b(sa, sb);
}

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack	*sa;
	t_stack	*sb;
	int		*n_array;
	int		size;

	if (argc > 1)
	{
		size = 0;
		all_checks_for_input(argv, &size);
		n_array = ft_calloc(size, sizeof(int));
		n_array = fill_array(argv, n_array);
		check_duplicates(n_array, size);
		sa = NULL;
		sb = NULL;
		stack_fill(&sa, n_array, size);
		if (!is_sorted(sa))
		{
			if (stack_len(sa) <= 3)
				sort_three(&sa);
			else
				big_sort(&sa, &sb);
		}
		free_memory(sa, sb, n_array);
	}
}

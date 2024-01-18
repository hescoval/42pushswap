/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:20 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/18 11:57:54 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef enum operations
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_operation;

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// main
void	print_error(void);
void	init_nodes_a(t_stack *sa, t_stack *sb);
void	init_nodes_b(t_stack *sa, t_stack *sb);
void	free_memory(t_stack *sa, t_stack *sb, int *n_array);

// input checker
long	ft_atol(char *str);
int		check_string(char **input, int *size);
int		check_input(char **input);
void	all_checks_for_input(char **input, int *size);

// array utils
int		*fill_array(char **argv, int *n_array);
void	check_duplicates(int *n_array, int size);
void	stack_fill(t_stack **stack, int *n_array, int size);
void	append_nodes(t_stack **stack, int number);
t_stack	*find_last_node(t_stack *stack);

// list utils
bool	is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	sort_three(t_stack **stack);
void	shift_stack(t_stack *popped);
t_stack	*find_biggest_node(t_stack *stack);

// list utils 2
void	current_index(t_stack *stack);
void	set_target_a(t_stack *sa, t_stack *sb);
void	check_cost_a(t_stack *sa, t_stack *sb);
void	set_cheapest(t_stack *stack);
void	big_sort(t_stack **sa, t_stack **sb);

// list utils 3
t_stack	*get_cheapest(t_stack *stack);
void	rotate_both(t_stack **sa, t_stack **sb, t_stack *cheap);
void	rev_rotate_both(t_stack **sa, t_stack **sb, t_stack *cheap);
void	prep_for_push(t_stack **stack, t_stack *node, char s_name);
void	move_a_to_b(t_stack **sa, t_stack **sb);

// list utils 4
t_stack	*find_min(t_stack *sa);
void	set_target_b(t_stack *sa, t_stack *sb);
void	move_b_to_a(t_stack **sa, t_stack **sb);
void	min_on_top(t_stack **sa);

// commands
void	do_op(t_stack **stack1, t_stack **stack2, t_operation op);
void	sx(t_stack **stack, char *str);
void	rrx(t_stack **stack, char *str);
void	rx(t_stack **stack, char *str);
void	px(t_stack **src, t_stack **dest, char *str);

// commands 2
void	rr(t_stack **sa, t_stack **sb, char *str);
void	rrr(t_stack **sa, t_stack **sb, char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:50:24 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:21:02 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(t_list *stack_a)
{
	int		a_size;
	t_list	*stack_b;

	stack_b = NULL;
	a_size = ft_lstsize(stack_a);
	if (a_size == 2)
		sa_swap(&stack_a, stack_a);
	if (a_size == 3)
		three_num(&stack_a);
	else
		sort_algorithm(&stack_a, &stack_b, a_size);
	free_lst(&stack_b);
	return (stack_a);
}

void	three_num(t_list **stack_a)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = *stack_a;
	two = one->next;
	three = two->next;
	if (one->index > two->index && one->index > three->index)
		ra_rotate(stack_a, *stack_a);
	if (two->index > one->index && two->index > three->index)
		rra_reverse(stack_a, *stack_a);
	one = *stack_a;
	two = one->next;
	three = two->next;
	if (one->index > two->index)
		sa_swap(stack_a, *stack_a);
}

void	sort_algorithm(t_list **stack_a, t_list **stack_b, int a_size)
{
	push_all_b(stack_a, stack_b, a_size);
	three_num(stack_a);
	while (*stack_b)
	{
		calc_objetive_pos(stack_a, stack_b);
		calc_num_movements(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	assign_pos(*stack_a);
	if (check_sort(*stack_a) == 1)
		last_sort_a(stack_a);
	assign_pos(*stack_a);
}

void	last_sort_a(t_list	**stack_a)
{
	int	size_a;
	int	middle_a;
	int	l_index_pos;

	size_a = ft_lstsize(*stack_a);
	middle_a = (size_a / 2);
	l_index_pos = get_pos_of_lowest_index(stack_a);
	if (l_index_pos > middle_a)
	{
		while (l_index_pos < size_a)
		{
			rra_reverse(stack_a, *stack_a);
			l_index_pos++;
		}
	}
	else
	{
		while (l_index_pos > 0)
		{
			ra_rotate(stack_a, *stack_a);
			l_index_pos--;
		}
	}
}

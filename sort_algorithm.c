/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:01:02 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:22:33 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_b(t_list **stack_a, t_list **stack_b, int a_size)
{
	t_list	*a;
	int		middle_size;
	int		i;
	int		pb_done;

	middle_size = (a_size / 2);
	i = 0;
	pb_done = 0;
	a = *stack_a;
	while (i < a_size && a_size - i > 3)
	{
		if (a->index <= middle_size)
		{
			pb_push(stack_a, stack_b);
			pb_done++;
		}
		else
			ra_rotate(stack_a, *stack_a);
		i++;
		a = *stack_a;
	}
	while ((a_size - pb_done++) > 3)
		pb_push(stack_a, stack_b);
}

//We look for the next index of b (b->index+1) in A, and it'll be the 
//"objetive"=objetive position of B in A.
//If b->index is bigger than any index in A, we look for the position of
// the lowest index in A.
void	calc_objetive_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		objetive_pos;
	int		objetive_index;

	b = *stack_b;
	objetive_pos = 0;
	objetive_index = INT_MAX;
	assign_pos(*stack_a);
	assign_pos(*stack_b);
	while (b)
	{
		objetive_pos = get_objetive_pos(stack_a, b->index, objetive_index,
				objetive_pos);
		b->objetive_pos = objetive_pos;
		b = b->next;
	}
}

int	get_objetive_pos(t_list **stack_a, int b_index, int objetive_index,
	int objetive_pos)
{
	t_list	*a;

	a = *stack_a;
	while (a)
	{
		if (a->index > b_index && a->index < objetive_index)
		{
			objetive_index = a->index;
			objetive_pos = a->pos;
		}
		a = a->next;
	}
	if (objetive_index == INT_MAX)
		objetive_pos = get_pos_of_lowest_index(stack_a);
	return (objetive_pos);
}

//Calculate the total movements we should do in A&B to order the element.
void	calc_num_movements(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;

	a = *stack_a;
	b = *stack_b;
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->movs_b = b->pos;
		if (b->pos > size_b / 2)
			b->movs_b = (size_b - b->pos) * (-1);
		b->movs_a = b->objetive_pos;
		if (b->objetive_pos > size_a / 2)
			b->movs_a = (size_a - b->objetive_pos) * (-1);
		b = b->next;
	}
}

void	cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		cheap;
	int		total_cost;
	int		movs_a;
	int		movs_b;

	b = *stack_b;
	cheap = INT_MAX;
	while (b)
	{
		total_cost = dis_to_zero(b->movs_a) + dis_to_zero(b->movs_b);
		if (total_cost < cheap)
		{
			cheap = total_cost;
			movs_a = b->movs_a;
			movs_b = b->movs_b;
		}
		b = b->next;
	}
	exe_moves(stack_a, stack_b, movs_a, movs_b);
}

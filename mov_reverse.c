/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:02:36 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:25:49 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Shift all elements of stack A down by 1 (1 2 4 9 0 -> 0 1 2 4 9)
void	rra_reverse(t_list	**stack_a, t_list *init_a)
{
	t_list	*last;
	t_list	*end;
	t_list	*before_end;

	last = ft_lstlast(init_a);
	end = last->next;
	before_end = init_a->next;
	while (before_end->next != last)
		before_end = before_end->next;
	before_end->next = end;
	last->next = init_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

//Shift all elements of stack B down by 1 (1 2 4 9 0 -> 0 1 2 4 9)
void	rrb_reverse(t_list	**stack_b, t_list *init_b)
{
	t_list	*last;
	t_list	*end;
	t_list	*before_end;

	last = ft_lstlast(init_b);
	end = last->next;
	before_end = init_b->next;
	while (before_end->next != last)
		before_end = before_end->next;
	before_end->next = end;
	last->next = init_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

//Shift all elements of stack A & B down by 1 at the same time 
void	rrr_reverse(t_list	**stack_a, t_list **stack_b)
{
	t_list	*last_a;
	t_list	*last_b;
	t_list	*end;
	t_list	*before_end;

	last_a = ft_lstlast(*stack_a);
	end = last_a->next;
	before_end = *stack_a;
	before_end = before_end->next;
	while (before_end->next != last_a)
		before_end = before_end->next;
	before_end->next = end;
	last_a->next = *stack_a;
	*stack_a = last_a;
	last_b = ft_lstlast(*stack_b);
	end = last_b->next;
	before_end = *stack_b;
	before_end = before_end->next;
	while (before_end->next != last_b)
		before_end = before_end->next;
	before_end->next = end;
	last_b->next = *stack_b;
	*stack_b = last_b;
	write(1, "rrr\n", 4);
}

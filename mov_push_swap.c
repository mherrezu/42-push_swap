/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:27:29 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:25:35 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Take the first element at the top of stack B and put it at the top of stack A.
//Do nothing if B is empty.
void	pa_push(t_list	**stack_a, t_list **stack_b)
{
	t_list	*init_a;
	t_list	*init_b;
	t_list	*aux;

	if (*stack_b)
	{
		init_a = NULL;
		init_b = *stack_b;
		init_b = init_b->next;
		aux = *stack_a;
		init_a = *stack_b;
		init_a->next = aux;
		*stack_a = init_a;
		*stack_b = init_b;
		write(1, "pa\n", 3);
	}
}

//Take the first element at the top of stack B and put it at the top of stack B.
//Do nothing if A is empty.
void	pb_push(t_list	**stack_a, t_list **stack_b)
{
	t_list	*init_a;
	t_list	*init_b;

	if (*stack_a)
	{
		init_a = *stack_a;
		init_a = init_a->next;
		init_b = *stack_a;
		init_b->next = *stack_b;
		*stack_a = init_a;
		*stack_b = init_b;
		write(1, "pb\n", 3);
	}
}

//Swap the first 2 elements at the top of stack A.
void	sa_swap(t_list **stack_a, t_list *init_a)
{
	t_list	*tmp;
	t_list	*aux;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = init_a->next;
		tmp = tmp->next;
		aux = init_a->next;
		aux->next = init_a;
		init_a->next = tmp;
		*stack_a = aux;
		write(1, "sa\n", 3);
	}
}

//Swap the first 2 elements at the top of stack B.
void	sb_swap(t_list **stack_b, t_list *init_b)
{
	t_list	*tmp;
	t_list	*aux;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = init_b->next;
		tmp = tmp->next;
		aux = init_b->next;
		aux->next = init_b;
		init_b->next = tmp;
		*stack_b = aux;
		write(1, "sb\n", 3);
	}
}

//Swap the first 2 elements at the top of stack A and B at the same time.
void	ss_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*aux;
	t_list	*init_a;
	t_list	*init_b;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		init_a = *stack_a;
		init_b = *stack_b;
		tmp = init_a->next;
		tmp = tmp->next;
		aux = init_a->next;
		aux->next = init_a;
		init_a->next = tmp;
		*stack_a = aux;
		tmp = init_b->next;
		tmp = tmp->next;
		aux = init_b->next;
		aux->next = init_b;
		init_b->next = tmp;
		*stack_b = aux;
		write(1, "ss\n", 3);
	}
}

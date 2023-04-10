/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:40:33 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:26:04 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //Shift all elements of stack A up by 1. (9 2 5 8 -> 2 5 8 9)
void	ra_rotate(t_list	**stack_a, t_list *init_a)
{
	t_list	*aux;
	t_list	*last;
	t_list	*end;

	aux = init_a;
	*stack_a = init_a->next;
	last = ft_lstlast(init_a);
	end = last->next;
	last->next = aux;
	aux->next = end;
	write(1, "ra\n", 3);
}

//Shift all elements of stack B up by 1. (9 2 5 8 -> 2 5 8 9)
void	rb_rotate(t_list	**stack_b, t_list *init_b)
{
	t_list	*aux;
	t_list	*last;
	t_list	*end;

	aux = init_b;
	*stack_b = init_b->next;
	last = ft_lstlast(init_b);
	end = last->next;
	last->next = aux;
	aux->next = end;
	write(1, "rb\n", 3);
}

// //Shift all elements of stack A & B up by 1 at the same time
void	rr_rotate(t_list	**stack_a, t_list **stack_b)
{
	t_list	*aux;
	t_list	*last;
	t_list	*end;
	t_list	*init_a;
	t_list	*init_b;

	init_a = *stack_a;
	init_b = *stack_b;
	aux = init_a;
	*stack_a = init_a->next;
	last = ft_lstlast(init_a);
	end = last->next;
	last->next = aux;
	aux->next = end;
	aux = init_b;
	*stack_b = init_b->next;
	last = ft_lstlast(init_b);
	end = last->next;
	last->next = aux;
	aux->next = end;
	write(1, "rr\n", 3);
}

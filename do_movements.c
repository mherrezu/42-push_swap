/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:17:44 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 12:04:41 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_moves(t_list **stack_a, t_list **stack_b, int movs_a, int movs_b)
{
	if (movs_a < 0 & movs_b < 0)
		exe_rev_both(stack_a, stack_b, &movs_a, &movs_b);
	else if (movs_a > 0 & movs_b > 0)
		exe_rot_both(stack_a, stack_b, &movs_a, &movs_b);
	exe_ra(stack_a, &movs_a);
	exe_rb(stack_b, &movs_b);
	pa_push(stack_a, stack_b);
}

void	exe_rev_both(t_list **stack_a, t_list **stack_b, int *movs_a,
		int *movs_b)
{
	while (*movs_a < 0 && *movs_b < 0)
	{
		rrr_reverse(stack_a, stack_b);
		(*movs_a)++;
		(*movs_b)++;
	}
}

void	exe_rot_both(t_list **stack_a, t_list **stack_b, int *movs_a,
		int *movs_b)
{
	while (*movs_a > 0 && *movs_b > 0)
	{
		rr_rotate(stack_a, stack_b);
		(*movs_a)--;
		(*movs_b)--;
	}
}

void	exe_ra(t_list **stack_a, int *movs_a)
{
	while (*movs_a)
	{
		if (*movs_a > 0)
		{
			ra_rotate(stack_a, *stack_a);
			(*movs_a)--;
		}
		else if (*movs_a < 0)
		{
			rra_reverse(stack_a, *stack_a);
			(*movs_a)++;
		}
	}
}

void	exe_rb(t_list **stack_b, int *movs_b)
{
	while (*movs_b)
	{
		if (*movs_b > 0)
		{
			rb_rotate(stack_b, *stack_b);
			(*movs_b)--;
		}
		else if (*movs_b < 0)
		{
			rrb_reverse(stack_b, *stack_b);
			(*movs_b)++;
		}
	}
}

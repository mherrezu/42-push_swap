/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:06:13 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:16:10 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(char **numbers)
{
	t_list	*stack;
	t_list	*new;
	int		i;

	i = 0;
	stack = NULL;
	new = NULL;
	stack = lst_new_node(ft_atoi(numbers[i]));
	while (numbers[++i])
	{
		new = lst_new_node(ft_atoi(numbers[i]));
		ft_lstadd_back(&stack, new);
	}
	free_array(numbers);
	assign_index(stack);
	assign_pos(stack);
	return (stack);
}

void	assign_index(t_list *lst)
{
	t_list	*actual_node;

	if (!lst)
		free_lst(&lst);
	actual_node = lst;
	while (actual_node)
	{
		actual_node -> index = calc_index(lst, actual_node);
		actual_node = actual_node -> next;
	}
}

int	calc_index(t_list *lst, t_list *actual_node)
{
	t_list	*compare;
	int		i;

	compare = lst;
	i = 1;
	while (compare)
	{
		if (compare->value < actual_node->value)
			i++;
		compare = compare->next;
	}
	return (i);
}

void	assign_pos(t_list *lst)
{
	t_list	*actual_node;
	int		i;

	i = 0;
	if (!lst)
		free_lst(&lst);
	actual_node = lst;
	while (actual_node)
	{
		actual_node -> pos = i++;
		actual_node = actual_node -> next;
	}
}

//If it's sort return 0, if NOT SORTED return 1.
int	check_sort(t_list *lst)
{
	t_list	*compare;
	t_list	*first;

	first = lst;
	compare = lst->next;
	while (first)
	{
		while (compare)
		{
			if (!(first->value <= compare->value))
				return (1);
			compare = compare->next;
		}
		compare = first->next;
		first = first->next;
	}
	return (0);
}

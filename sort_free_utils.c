/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:19:57 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:22:59 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_of_lowest_index(t_list **stack_a)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_index_pos;

	tmp = *stack_a;
	lowest_index = INT_MAX;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_index_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_index_pos);
}

int	dis_to_zero(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	free_array(char	**numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
	{	
		free(numbers[i]);
		i++;
	}
	free(numbers[i]);
	free(numbers);
}

void	free_lst(t_list	**lst)
{
	t_list	*node;

	node = *lst;
	while (node)
	{	
		free(node);
		node = node->next;
	}
	free(node);
}

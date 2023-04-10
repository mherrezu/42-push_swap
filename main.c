/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:03:13 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:13:05 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_leak(void)
{
		system("leaks -q push_swap");
}
*/
int	main(int argc, char **argv)
{
	int			check;
	char		**numbers;
	t_list		*stack_a;

//	atexit(ft_leak);
	numbers = NULL;
	stack_a = NULL;
	check = 0;
	(void) argv;
	if (argc <= 1)
		return (0);
	numbers = check_arguments(argc, argv);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = create_list(numbers);
	if (!stack_a)
		return (free_lst(&stack_a), 0);
	check = check_sort(stack_a);
	if (check == 1)
	{
		stack_a = push_swap(stack_a);
	}
	free_lst(&stack_a);
	return (0);
}

/* Itera la lista ’lst’ e imprime
contenido de cada nodo. */
void	ft_lstprinter(t_list *lst)
{
	while (lst)
	{
		printf("%i - ", lst -> pos);
		printf("%i - ", lst -> index);
		printf("%i\n", lst -> value);
		lst = lst -> next;
	}
}

void	printer_target(t_list *lst)
{
	printf("T - P - I - V\n");
	while (lst)
	{
		printf("%i - ", lst -> objetive_pos);
		printf("%i - ", lst -> pos);
		printf("%i - ", lst -> index);
		printf("%i\n", lst -> value);
		lst = lst -> next;
	}
}

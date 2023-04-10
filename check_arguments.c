/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:37:29 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:14:34 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//First, we put the arguments in an array if its passed as one "string"
//or different argv. 
char	**check_arguments(int argc, char **argv)
{
	char	**numbers;
	int		i;

	if (!argv)
		return (NULL);
	numbers = NULL;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		numbers = malloc(argc * sizeof(char *));
		if (!numbers)
			return (free(numbers), NULL);
		i = 0;
		while (argv[i + 1])
		{
			numbers[i] = ft_strcpy(numbers[i], argv[i + 1]);
			i++;
		}
		numbers[i] = NULL;
	}
	if (check_numbers(numbers) == 0)
		return (free_array(numbers), NULL);
	return (numbers);
}

//Second, check the strings of array. If they are digits, - or +, 
//or check if they are integrer or not.
int	check_numbers(char **numbers)
{
	int			i;
	int			c;
	long long	long_num;

	i = 0;
	c = 0;
	if (!*numbers || !**numbers)
		return (0);
	while (numbers[i])
	{
		if (numbers[i][c] == '-' || numbers[i][c] == '+')
			c++;
		while (ft_isdigit(numbers[i][c]) == 1)
			c++;
		if (numbers[i][c] != '\0' || numbers[i][--c] == '-' ||
			numbers[i][c] == '+')
			return (0);
		long_num = atoll(numbers[i]);
		if (!(long_num >= -2147483648 && long_num <= 2147483647))
			return (0);
		i++;
		c = 0;
	}
	c = duplicheck(numbers);
	return (c);
}

//Third, to check if they are integrer or not, we pass the string 
//to a long long so we can check the limits of int.
long long	atoll(const char *str)
{
	long long	c;
	long long	sign;
	long long	result;

	c = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\f'
		|| str[c] == '\r' || str[c] == '\t' || str[c] == '\v')
		c++;
	sign = 1;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign = sign * (-1);
		c++;
	}
	result = 0;
	while (str[c] >= '0' && str[c] <= '9')
	{	
		result = (result * 10) + (str[c] - 48);
		c++;
	}
	return (result * sign);
}

//Check duplicates. Return 1 if no coincidence, 0 if there's a duplicate.
int	duplicheck(char **numbers)
{
	int		i;
	int		j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[j]) == ft_atoi(numbers[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//ATOI: change an str to integer
int	ft_atoi(const char *str)
{
	int	c;
	int	sign;
	int	result;

	c = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\f'
		|| str[c] == '\r' || str[c] == '\t' || str[c] == '\v')
	{
		c++;
	}
	sign = 1;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign = sign * (-1);
		c++;
	}
	result = 0;
	while (str[c] >= '0' && str[c] <= '9')
	{	
		result = (result * 10) + (str[c] - 48);
		c++;
	}
	return (result * sign);
}

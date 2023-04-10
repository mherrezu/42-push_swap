/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:23:03 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:17:31 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SPLIT
int	count_words(char const *s, char c)
{
	int	c_words;
	int	found;
	int	i;

	c_words = 0;
	found = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && found == 0)
		{
			c_words++;
			found = 1;
		}
		else if (s[i] == c)
			found = 0;
		i++;
	}
	return (c_words);
}

char	*fill_word(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (free(word), NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = 0;
	return (word);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	size_t	finish;
	size_t	j;

	array = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !array)
		return (free(array), NULL);
	finish = 0;
	start = -1;
	j = 0;
	while (finish <= ft_strlen(s))
	{
		if (s[finish] != c && start < 0)
			start = finish;
		else if ((s[finish] == c || finish == ft_strlen(s)) && start >= 0)
		{
			array[j++] = fill_word(s, start, finish);
			start = -1;
		}
		finish++;
	}
	array[j] = 0;
	return (array);
}

//STRCPY - I changed it from Libft. Now it allocates memmory.
char	*ft_strcpy(char *dest, char *src)
{
	int		c;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (free(dest), NULL);
	c = 0;
	while (src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}

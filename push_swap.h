/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:24:36 by mherrezu          #+#    #+#             */
/*   Updated: 2023/04/10 14:28:29 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647 
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//Struct to create the list of stack A & B
typedef struct list
{
	int				value;
	int				index;
	int				pos;
	int				objetive_pos;
	int				movs_a;
	int				movs_b;
	struct list		*next;
}	t_list;

//MAIN.C
int			main(int argc, char **argv);
void		ft_lstprinter(t_list *lst); //Para imprimir y comprobar que esté OK
void		printer_target(t_list *lst);

//CHECK_ARGUMENTS.C
char		**check_arguments(int argc, char **argv);
int			check_numbers(char **numbers);
long long	atoll(const char *str);
int			duplicheck(char **numbers);
int			ft_atoi(const char *str);

//LIBFT_UTILS.C
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dest, char *src); //Malloc added

//GENERATE_LIST.C
t_list		*create_list(char **numbers);
void		assign_index(t_list *lst);
int			calc_index(t_list *lst, t_list *actual_node);
void		assign_pos(t_list *lst);
int			check_sort(t_list *lst);

//LIST_UTILS.C
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
t_list		*lst_new_node(int number);
int			ft_isdigit(int c);

//PUSH_SWAP.C
t_list		*push_swap(t_list *lst);
void		three_num(t_list **stack_a);
void		sort_algorithm(t_list **stack_a, t_list **stack_b, int a_size);
void		last_sort_a(t_list	**stack_a);

//SORT_ALGORITHM.C
void		push_all_b(t_list **stack_a, t_list **stack_b, int a_size);
void		calc_objetive_pos(t_list **stack_a, t_list **stack_b);
int			get_objetive_pos(t_list **stack_a, int b_index, int objetive_index,
				int objetive_pos);
void		calc_num_movements(t_list **stack_a, t_list **stack_b);
void		cheapest_move(t_list **stack_a, t_list **stack_b);

//DO_MOVEMENTS.C
void		exe_moves(t_list **stack_a, t_list **stack_b, int movs_a,
				int movs_b);
void		exe_rev_both(t_list **stack_a, t_list **stack_b, int *movs_a,
				int *movs_b);
void		exe_rot_both(t_list **stack_a, t_list **stack_b, int *movs_a,
				int *movs_b);
void		exe_ra(t_list **stack_a, int *movs_a);
void		exe_rb(t_list **stack_b, int *movs_b);

//SORT_FREE_UTILS.C
int			get_pos_of_lowest_index(t_list **stack_a);
int			dis_to_zero(int num);
void		free_array(char	**numbers);
void		free_lst(t_list	**lst);

//MOV_PUSH_SWAP.C
void		pa_push(t_list	**stack_a, t_list **stack_b);
void		pb_push(t_list	**stack_a, t_list **stack_b);
void		sa_swap(t_list **stack_a, t_list *init_a);
void		sb_swap(t_list **stack_b, t_list *init_b);
void		ss_swap(t_list **stack_a, t_list **stack_b);

//MOV_ROTATE.C
void		ra_rotate(t_list	**stack_a, t_list *init_a);
void		rb_rotate(t_list	**stack_b, t_list *init_b);
void		rr_rotate(t_list	**stack_a, t_list **stack_b);

//MOV_REVERSE.C
void		rra_reverse(t_list	**stack_a, t_list *init_a);
void		rrb_reverse(t_list	**stack_b, t_list *init_b);
void		rrr_reverse(t_list	**stack_a, t_list **stack_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:55:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/04/06 04:48:25 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

//ft_main.c
int		main(int argc, char **argv);
int		parse_args(int argc, char **argv, t_stacks *stacks, char ***args);
int		is_number(char *str);
int		free_all(t_stacks *stacks, char **args, int argc, int error);
int		check_duplicate(t_stacks *stacks);

//ft_little_sort.c
t_list	*find_max(t_list *stack);
void	sort_three(t_stacks *stacks);
int		count_elements(t_list *stack);
int		is_sorted(t_list *stack);
void	sort_stack(t_stacks *stacks);

//ft_big_sort.c
void	big_sort(t_stacks *stacks);
void	min_on_top(t_stacks *stacks, t_list **a);
t_list	*find_min(t_list *stack);

//ft_init.c
void	init_nodes(t_stacks *stacks);
void	set_index_median(t_list *stack);
void	set_target(t_stacks *stacks);
void	cost_analysis(t_stacks *stacks);
void	set_cheapest(t_list *stack);

//ft_move.c
void	move_a_to_b(t_stacks *stacks);
t_list	*get_cheapest(t_list *stack);
void	rotate_booth(t_stacks *stacks, t_list *cheapest_node);
void	rev_rotate_booth(t_stacks *stacks, t_list *cheapest_node);
void	prep_for_push(t_stacks *stacks, t_list **stack, \
t_list *cheapest_node, char stack_name);

//ft_swap.c
void	swap(t_list **stack);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//ft_push.c
void	push(t_list **src, t_list **dest);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

//ft_rotate
void	rotate(t_list **stack);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//ft_reverse.c
void	reverse_rotate(t_list **stack);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

void	sort_five(t_stacks *stacks);

#endif

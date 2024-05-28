/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:32 by bdellaro          #+#    #+#             */
/*   Updated: 2024/04/30 12:12:26 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h> 

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}			t_stacks;

void	ft_push(t_list **src, t_list **dest);
void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_reverse_rotate(t_list **stack);
void	ft_rra(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);
void	ft_rotate(t_list **stack);
void	ft_ra(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_swap(t_list **stack);
void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);
void	ft_sort_five(t_stacks *stacks);
t_list	*ft_find_max(t_list *stack);
void	ft_sort_three(t_stacks *stacks);
int		ft_count_elements(t_list *stack);
int		ft_is_sorted(t_list *stack);
void	ft_sort_stack(t_stacks *stacks);
void	ft_big_sort(t_stacks *stacks);
void	ft_min_on_top(t_stacks *stacks, t_list **a);
t_list	*ft_find_min(t_list *stack);
void	ft_init_nodes(t_stacks *stacks);
void	ft_set_index_median(t_list *stack);
void	ft_set_target(t_stacks *stacks);
void	ft_cost_analysis(t_stacks *stacks);
void	ft_set_cheapest(t_list *stack);
void	ft_move_a_to_b(t_stacks *stacks);
t_list	*ft_get_cheapest(t_list *stack);
void	ft_rotate_booth(t_stacks *stacks, t_list *cheapest_node);
void	ft_rev_rotate_booth(t_stacks *stacks, t_list *cheapest_node);
void	ft_prep_for_push(t_stacks *stacks, t_list **stack, \
t_list *ft_cheapest_node, char stack_name);
int		ft_parse_args(int argc, char **argv, t_stacks *stacks, char ***args);
int		ft_is_number(char *str);
int		ft_free_all(t_stacks *stacks, char **args, int argc, int error);
int		ft_check_duplicate(t_stacks *stacks);

#endif

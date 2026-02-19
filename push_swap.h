/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:58:55 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/19 16:37:46 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

void	ft_pa_pb(t_node **from, t_node **to);
void	ft_ra_rb(t_node **stack);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra_rrb(t_node **stack);
void	ft_rrr(t_node **stack_a, t_node **stack_b);
void	ft_sa_sb(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_node **a);
void	ft_simple_algo(t_node **stack_a, t_node **stack_b);
void	ft_medium_algo(t_node **a, t_node **b);
void	ft_complex_algo(t_node **a, t_node **b);
void	ft_adaptive_algo(t_node **stack_a, t_node **stack_b);
void	print_stack(t_node *stack);
void	add_back(t_node **stack, t_node *new);
int		find_max(t_node **top);
int		find_min(t_node **top);
int		count_stack(t_node **top);
int		calc_end_idx(int start, int chunk_size, int total_size);
int		is_in_chunk(int value, int *sorted_array, int start_idx,
						int end_idx);
int		is_number(const char *str);
int		parse_one_number(char **argv, int *i, t_node **stack_a);
float	compute_disorder(t_node **a);
t_node	*new_node(int value);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_pb(t_node **a, t_node **b);
void	ft_pa(t_node **b, t_node **a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:23:56 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/19 16:49:49 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	bits;

	max_num = size - 1;
	bits = 0;
	while (max_num >> bits)
		bits++;
	return (bits);
}

static int	stack_size(t_node *s)
{
	int	i;

	i = 0;
	while (s && ++i)
		s = s->next;
	return (i);
}

static int	count_smaller(t_node *stack, int target_value)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->value < target_value)
			count++;
		stack = stack->next;
	}
	return (count);
}

static void	normalize_to_indices(t_node **stack)
{
	t_node	*current;
	int		original_value;
	int		index;

	current = *stack;
	while (current)
	{
		original_value = current->value;
		index = count_smaller(*stack, original_value);
		current->value = index;
		current = current->next;
	}
}

void	ft_complex_algo(t_node **a, t_node **b)
{
	int	bit;
	int	max_bits;
	int	pushed;
	int	size;
	int	i;

	bit = 0;
	size = stack_size(*a);
	normalize_to_indices(a);
	max_bits = get_max_bits(size);
	while (bit < max_bits)
	{
		i = 0;
		pushed = 0;
		while (i++ < size)
		{
			if ((((*a)->value >> bit) & 1) == 0)
			{
				ft_pb(a, b);
				pushed++;
			}
			else
				ft_ra(a);
		}
		while (pushed--)
			ft_pa(a, b);
		bit++;
	}
}

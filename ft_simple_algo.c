/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:58:32 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/17 15:06:36 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_list(t_node **stack_a)
{
	int		min;
	t_node	*current;

	if (!stack_a)
		return (0);
	min = (*stack_a)->value;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

void	ft_simple_algo(t_node **stack_a, t_node **stack_b)
{
	int	min;

	while (*stack_a)
	{
		min = min_list(stack_a);
		while ((*stack_a)->value != min)
		{
			ft_ra_rb(stack_a);
			write(1, "ra\n", 3);
		}
		ft_pa_pb(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	while (*stack_b)
	{
		ft_pa_pb(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

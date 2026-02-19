/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:22:28 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/19 16:38:39 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	first->next = NULL;
	last->next = first;
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_ra_rb(stack_a);
	ft_ra_rb(stack_b);
}

void	ft_rra_rrb(t_node **stack)
{
	t_node	*last;
	t_node	*previous;

	if (!(*stack) || !(*stack)->next)
		return ;
	previous = NULL;
	last = *stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	previous->next = NULL;
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_rra_rrb(stack_a);
	ft_rra_rrb(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:04:13 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/12 15:18:37 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*three;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	three = second->next;
	first->next = three;
	second->next = first;
	*stack = second;
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
}

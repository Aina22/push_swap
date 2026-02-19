/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:04:13 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/19 12:47:41 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
}

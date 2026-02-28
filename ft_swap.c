/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:06:11 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/28 11:25:26 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	ft_sa_sb(t_node **stack)
{
	int	temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	ft_ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
	if (!bench)
		write(1, "ss\n", 3);
	if (bench)
		bench_ss(bench);
}

void	ft_sa(t_node **a, t_bench *bench)
{
	ft_sa_sb(a);
	if (!bench)
		write(1, "sa\n", 3);
	if (bench)
		bench_sa(bench);
}

void	ft_sb(t_node **b, t_bench *bench)
{
	ft_sa_sb(b);
	if (!bench)
		write(1, "sb\n", 3);
	if (bench)
		bench_sb(bench);
}

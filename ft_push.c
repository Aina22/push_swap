/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:05:43 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/28 11:25:13 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	ft_pa_pb(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	ft_pb(t_node **b, t_node **a, t_bench *bench)
{
	ft_pa_pb(b, a);
	if (!bench)
		write(1, "pb\n", 3);
	if (bench)
		bench_pb(bench);
}

void	ft_pa(t_node **a, t_node **b, t_bench *bench)
{
	ft_pa_pb(a, b);
	if (!bench)
		write(1, "pa\n", 3);
	if (bench)
		bench_pa(bench);
}

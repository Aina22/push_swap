/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:05:49 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/28 11:25:57 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	ft_ra(t_node **a, t_bench *bench)
{
	ft_ra_rb(a);
	if (!bench)
		write(1, "ra\n", 3);
	if (bench)
		bench_ra(bench);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_shower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:56:03 by ainadan           #+#    #+#             */
/*   Updated: 2026/02/26 16:57:03 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

char	*get_strategy_name(char *flag, float disorder)
{
	if (flag)
	{
		if (!ft_strcmp(flag, "--simple"))
			return ("Simple / O(n²)");
		if (!ft_strcmp(flag, "--medium"))
			return ("Medium / O(n√n)");
		if (!ft_strcmp(flag, "--complex"))
			return ("Complex / O(n log n)");
	}
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

void	run_benchmark(t_node **a, t_node **b, char *flag)
{
	t_bench	bench;
	float	disorder;
	char	*strategy;

	init_bench(&bench);
	disorder = compute_disorder(a);
	strategy = get_strategy_name(flag, disorder);
	if (flag)
		exec_algo(flag, a, b, &bench);
	else
		ft_adaptive_algo(a, b, &bench);
	print_bench(&bench, disorder, strategy);
}

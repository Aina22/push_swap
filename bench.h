/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:09:55 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/26 16:54:56 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include "push_swap.h"

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_bench;

void	init_bench(t_bench *bench);
int		get_total_ops(t_bench *bench);
void	print_bench(t_bench *bench, float disorder, char *strategy);
void	bench_sa(t_bench *bench);
void	bench_sb(t_bench *bench);
void	bench_ss(t_bench *bench);
void	bench_pa(t_bench *bench);
void	bench_pb(t_bench *bench);
void	bench_ra(t_bench *bench);
void	bench_rb(t_bench *bench);
void	bench_rr(t_bench *bench);
void	bench_rra(t_bench *bench);
void	bench_rrb(t_bench *bench);
void	bench_rrr(t_bench *bench);
void	run_benchmark(t_node **a, t_node **b, char *flag);
char	*get_strategy_name(char *flag, float disorder);

#endif
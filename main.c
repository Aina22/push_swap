/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:06:21 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 11:06:22 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bench.h"
#include "push_swap.h"

static int	is_bench_flag(char *arg)
{
	return (!ft_strcmp(arg, "--bench"));
}

static int	init_vars(int ac, char **av, char **flag, int *i, int *bench_mode)
{
	*flag = NULL;
	*bench_mode = 0;
	if (ac < 2)
		return (print_error(), 1);
	if (is_bench_flag(av[1]))
	{
		*bench_mode = 1;
		*i = 2;
		if (*i < ac && is_valid_flag(av[*i]))
		{
			*flag = av[*i];
			(*i)++;
		}
	}
	else if (is_valid_flag(av[1]))
	{
		*flag = av[1];
		*i = 2;
	}
	else
		*i = 1;
	if (*bench_mode && *i >= ac)
		return (print_error(), 1);
	if (!*bench_mode && *i >= ac)
		return (print_error(), 1);
	return (0);
}

static char	*get_strategy_name(char *flag, float disorder)
{
	if (flag)
	{
		if (!ft_strcmp(flag, "--simple"))
			return ("Simple / O(n²)");
		else if (!ft_strcmp(flag, "--medium"))
			return ("Medium / O(n√n)");
		else if (!ft_strcmp(flag, "--complex"))
			return ("Complex / O(n log n)");
	}
	if (disorder < 0.2)
		return ("Adaptive (Simple) / O(n²)");
	else if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive (Medium) / O(n√n)");
	else
		return ("Adaptive (Complex) / O(n log n)");
}

static int	parse_and_check(int ac, char **av, int i, t_node **a)
{
	int	num_count;

	num_count = count_total_numbers(ac, av, i);
	if (num_count <= 0)
		return (print_error(), 1);
	if (!parse_args(ac, av, i, a))
		return (free_stack(a), print_error(), 1);
	if (check_duplicates(*a))
		return (free_stack(a), print_error(), 1);
	return (num_count);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*flag;
	int		i;
	int		num_count;
	int		bench_mode;
	t_bench	bench;
	float	disorder;
	char	*strategy_name;

	a = NULL;
	b = NULL;
	if (init_vars(ac, av, &flag, &i, &bench_mode))
		return (1);
	num_count = parse_and_check(ac, av, i, &a);
	if (num_count == 1)
		return (free_stack(&a), 0);
	if (num_count < 0)
		return (1);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	if (bench_mode)
	{
		init_bench(&bench);
		disorder = compute_disorder(&a);
		strategy_name = get_strategy_name(flag, disorder);
		if (flag)
			exec_algo(flag, &a, &b, &bench);
		else
			ft_adaptive_algo(&a, &b, &bench);
		print_bench(&bench, disorder, strategy_name);
	}
	else
	{
		if (flag)
			exec_algo(flag, &a, &b, NULL);
		else
			ft_adaptive_algo(&a, &b, NULL);
	}
	return (free_stack(&a), free_stack(&b), 0);
}

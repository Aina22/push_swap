/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:06:21 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/26 16:51:44 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

static int	init_vars(int ac, char **av, char **flag, int *bench_mode)
{
	int	i;

	*flag = NULL;
	*bench_mode = 0;
	i = 1;
	if (ac <= 1)
		return (0);
	if (!ft_strcmp(av[1], "--bench"))
	{
		*bench_mode = 1;
		i = 2;
		if (i < ac && is_valid_flag(av[i]))
			*flag = av[i++];
	}
	else if (is_valid_flag(av[1]))
	{
		*flag = av[1];
		i = 2;
	}
	if (i >= ac)
		return (print_error(), -1);
	return (i);
}

static int	parse_and_check(int ac, char **av, int i, t_node **a)
{
	int	num_count;

	num_count = count_total_numbers(ac, av, i);
	if (num_count <= 0)
		return (print_error(), -1);
	if (!parse_args(ac, av, i, a))
	{
		free_stack(a);
		return (print_error(), -1);
	}
	if (check_duplicates(*a))
	{
		free_stack(a);
		return (print_error(), -1);
	}
	return (num_count);
}

static int	handle_no_args(int i, int ac)
{
	if (i == 0 && ac <= 1)
		return (1);
	return (0);
}

static void	run_normal_mode(t_node **a, t_node **b, char *flag, int bench_mode)
{
	if (bench_mode)
		run_benchmark(a, b, flag);
	else if (flag)
		exec_algo(flag, a, b, NULL);
	else
		ft_adaptive_algo(a, b, NULL);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*flag;
	int		i;
	int		bench_mode;

	a = NULL;
	b = NULL;
	i = init_vars(ac, av, &flag, &bench_mode);
	if (handle_no_args(i, ac))
		return (0);
	if (i == -1 || parse_and_check(ac, av, i, &a) <= 0)
		return (1);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	run_normal_mode(&a, &b, flag, bench_mode);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

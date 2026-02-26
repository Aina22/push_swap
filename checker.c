/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:25:52 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/26 17:03:39 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	fill_stack_string(char *str, t_node **a)
{
	int		i;
	int		count;
	char	*num;

	count = count_numbers(str);
	i = 0;
	while (i < count)
	{
		num = extract_number(str, i);
		if (!num || !is_number(num))
		{
			ft_putstr_fd("Error\n", 2);
			free(num);
			return (-1);
		}
		add_back(a, new_node(ft_atoi(num)));
		free(num);
		i++;
	}
	return (0);
}

static int	read_commands(t_node **a, t_node **b)
{
	int	input;
	int	eof;

	eof = 0;
	while (!eof)
	{
		input = user_input(a, b, &eof);
		if (input == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	parse_string(char *str)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (fill_stack_string(str, &a) == -1)
		return (free_stack(&a), -1);
	if (read_commands(&a, &b) == -1)
		return (free_stack(&a), free_stack(&b), -1);
	stack_in_order(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		return (parse_string(av[1]));
	return (parse_checker_args(ac, av));
}

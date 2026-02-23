/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:26:32 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/21 13:28:14 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	extract_number(char *str, int *i, char **start, int *len)
{
	while (str[*i] == ' ')
		(*i)++;
	if (!str[*i])
		return (0);
	*start = &str[*i];
	*len = 0;
	if (str[*i] == '-')
	{
		(*len)++;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*len)++;
		(*i)++;
	}
	return (*len > 0);
}

static int	process_number(char *num_str, t_node **a)
{
	int	value;

	if (!is_valid_number(num_str))
		return (free(num_str), 0);
	value = ft_atoi(num_str);
	free(num_str);
	add_back(a, new_node(value));
	return (1);
}

int	parse_str(char *str, t_node **a)
{
	int		i;
	char	*start;
	char	*num_str;
	int		len;

	i = 0;
	while (str[i])
	{
		if (!extract_number(str, &i, &start, &len))
		{
			if (str[i] && str[i] != ' ')
				return (0);
			break ;
		}
		num_str = malloc(len + 1);
		if (!num_str)
			return (0);
		ft_strlcpy(num_str, start, len + 1);
		if (!process_number(num_str, a))
			return (0);
	}
	return (1);
}

int	parse_args(int ac, char **av, int start_idx, t_node **a)
{
	int	i;

	i = start_idx;
	while (i < ac)
	{
		if (!parse_str(av[i], a))
			return (0);
		i++;
	}
	return (1);
}

int	count_total_numbers(int ac, char **av, int start_idx)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = start_idx - 1;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (ft_isdigit(av[i][j]) || av[i][j] == '-')
			{
				count++;
				if (av[i][j] == '-')
					j++;
				while (ft_isdigit(av[i][j]))
					j++;
			}
			else if (av[i][j])
				return (-1);
		}
	}
	return (count);
}

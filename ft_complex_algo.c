/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:23:56 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/17 13:20:26 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *s)
{
	int	m;
	int	b;

	m = 0;
	b = 0;
	while (s)
	{
		if (s->value > m)
			m = s->value;
		if (m < 0)
			break ;
		s = s->next;
	}
	while (m >> b)
		b++;
	return (b);
}

static int	stack_size(t_node *s)
{
	int	i;

	i = 0;
	while (s && ++i)
		s = s->next;
	return (i);
}

static void	ft_pb(t_node **a, t_node **b)
{
	ft_pa_pb(a, b);
	write(1, "pb\n", 3);
}

static void	ft_pa(t_node **b, t_node **a)
{
	ft_pa_pb(b, a);
	write(1, "pa\n", 3);
}

void	ft_complex_algo(t_node **a, t_node **b)
{
	int	i;
	int	j;
	int	mb;
	int	sz;

	sz = stack_size(*a);
	mb = get_max_bits(*a);
	i = -1;
	while (++i < mb)
	{
		j = -1;
		while (++j < sz)
		{
			if ((((*a)->value >> i) & 1) == 0)
				ft_pb(a, b);
			else
			{
				ft_ra_rb(a);
				write(1, "ra\n", 3);
			}
		}
		while (*b)
			ft_pa(b, a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:45:41 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/19 17:11:01 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_node **stack, t_node *new);
t_node	*new_node(int value);
void	print_stack(t_node *stack);
static void	sort_array(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sort_array(int size, t_node *top)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	cur = top;
	i = 0;
	while (i < size && cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	sort_array(arr, size);
	return (arr);
}

static void	push_chunks_to_b(t_node **a, t_node **b, int *arr, int size)
{
	int	chunk;
	int	start;
	int	end;
	int	found;

	chunk = 10;
	start = 0;
	while (start < size)
	{
		end = calc_end_idx(start, chunk, size);
		found = 0;
		while (found++ < end - start)
		{
			if (is_in_chunk((*a)->value, arr, start, end))
			{
				ft_pa_pb(a, b);
				write(1, "pb\n", 3);
			}
			else
				ft_ra(a);
		}
		start += chunk;
	}
}

void	ft_medium_algo(t_node **a, t_node **b)
{
	int	total_size;
	int	*array;
	int	max_val;

	total_size = count_stack(a);
	array = create_sort_array(total_size, *a);
	push_chunks_to_b(a, b, array, total_size);
	while (*b != NULL)
	{
		max_val = find_max(b);
		while ((*b)->value != max_val)
		{
			ft_ra_rb(b);
			write(1, "rb\n", 3);
		}
		ft_pa_pb(b, a);
		write(1, "pa\n", 3);
	}
	free(array);
}

// int main(void)
// {
// 	t_node	*stack_a = NULL;
// 	t_node	*stack_b = NULL;

// 	add_back(&stack_a, new_node(2));
// 	add_back(&stack_a, new_node(5));
// 	add_back(&stack_a, new_node(4));
// 	add_back(&stack_a, new_node(3));

// 	ft_medium_algo(&stack_a, &stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	return (0);
// }

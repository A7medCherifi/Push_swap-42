/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:18 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:44:59 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_top(t_stack **a, int median, int position, int size)
{
	int	moves;

	if (position > median)
	{
		moves = size - position;
		while (moves > 0)
		{
			rra(a, 1);
			moves--;
		}
	}
	else
	{
		moves = position;
		while (moves > 0)
		{
			ra(a, 1);
			moves--;
		}
	}
}

void	last_sort_a(t_stack **a)
{
	t_stack	*ptr;
	int		median;
	int		size;
	long	min;
	int		position;

	ptr = *a;
	position = 0;
	min = LONG_MAX;
	size = lst_size(*a);
	median = size / 2;
	assign_positions(ptr);
	while (ptr)
	{
		if (ptr->index < min)
		{
			min = ptr->index;
			position = ptr->position;
		}
		ptr = ptr->next;
	}
	push_min_top(a, median, position, size);
}

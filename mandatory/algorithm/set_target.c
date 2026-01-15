/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:01 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:51:26 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_less_move(t_stack *b)
{
	t_stack	*head;
	long	min;
	int		position;
	int		total;

	head = b;
	min = LONG_MAX;
	position = 0;
	while (head)
	{
		total = head->cost_a;
		if (total < 0)
			total *= -1;
		if (head->cost_b < 0)
			total += head->cost_b * -1;
		else
			total += head->cost_b;
		if (total < min)
		{
			min = total;
			position = head->position;
		}
		head = head->next;
	}
	return (position);
}

static void	count_moves(t_stack *lst, int position, int *cost)
{
	int	median;
	int	size;

	size = lst_size(lst);
	median = size / 2;
	if (position <= median)
		*cost = position;
	else if (position > median)
		*cost = position - size;
}

static int	get_target(t_stack *a, t_stack **b, long value)
{
	int	res;

	res = 0;
	while (a)
	{
		if ((*b)->index < a->index && a->index < value)
		{
			value = a->index;
			(*b)->target = a;
			res = 1;
		}
		a = a->next;
	}
	return (res);
}

static void	get_min_target(t_stack *a, t_stack **b, long value)
{
	while (a)
	{
		if (a->index < value)
		{
			value = a->index;
			(*b)->target = a;
		}
		a = a->next;
	}
}

void	count_target(t_stack *a, t_stack **b)
{
	t_stack	*ptr;
	long	value;

	ptr = *b;
	assign_positions(a);
	assign_positions(ptr);
	while (ptr)
	{
		value = LONG_MAX;
		if (!get_target(a, &ptr, value))
			get_min_target(a, &ptr, value);
		count_moves(a, ptr->target->position, &ptr->cost_a);
		count_moves(*b, ptr->position, &ptr->cost_b);
		ptr = ptr->next;
	}
}

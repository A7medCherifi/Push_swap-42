/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:15 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:46:30 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_a_rotater(t_stack **a, int cost)
{
	if (cost > 0)
	{
		while (cost-- > 0)
			ra(a, 1);
	}
	else if (cost < 0)
	{
		while (cost++ < 0)
			rra(a, 1);
	}
}

static void	cost_b_rotater(t_stack **b, int cost)
{
	if (cost > 0)
	{
		while (cost-- > 0)
			rb(b, 1);
	}
	else if (cost < 0)
	{
		while (cost++ < 0)
			rrb(b, 1);
	}
}

static void	cost_routate(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, 1);
		cost_a++;
		cost_b++;
	}
	cost_a_rotater(a, cost_a);
	cost_b_rotater(b, cost_b);
}

static void	push_to_target(t_stack **a, t_stack **b, int position)
{
	t_stack	*ptr;
	int		cost_a;
	int		cost_b;

	ptr = *b;
	while (ptr->position != position)
		ptr = ptr->next;
	cost_a = ptr->cost_a;
	cost_b = ptr->cost_b;
	cost_routate(a, b, cost_a, cost_b);
	pa(a, b, 1);
}

void	sort_push_a(t_stack **a, t_stack **b)
{
	int	position;

	while (*b)
	{
		count_target(*a, b);
		position = get_less_move(*b);
		push_to_target(a, b, position);
	}
	last_sort_a(a);
}

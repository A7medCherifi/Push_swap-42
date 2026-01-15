/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:06 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:49:31 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first < second && second > third && third > first)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && third < first)
		rra(a, 1);
}

static void	sort_two_numbers(t_stack **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		rra(a, 1);
}

static void	sort_rest(t_stack **a, int size)
{
	if (size == 3)
		sort_three_numbers(a);
	else if (size == 2)
		sort_two_numbers(a);
	else
		return ;
}

static void	check_and_rotate(t_stack **b, int median)
{
	if ((*b)->next == NULL)
		return ;
	if ((*b)->index > median)
		rb(b, 1);
}

void	push_stack_b(t_stack **a, t_stack **b)
{
	int		size;
	int		median;

	size = lst_size(*a);
	median = size / 2;
	while (size > 3)
	{
		pb(b, a, 1);
		check_and_rotate(b, median);
		size--;
	}
	sort_rest(a, size);
	sort_push_a(a, b);
}

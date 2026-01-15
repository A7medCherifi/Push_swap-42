/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:24 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:35:24 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate_func(t_stack **lst)
{
	t_stack	*node;
	t_stack	*prev;
	t_stack	*head;
	t_stack	*last;

	if (!*lst || !(*lst)->next)
		return ;
	node = *lst;
	head = *lst;
	while (node->next)
	{
		if (node->next->next == NULL)
			prev = node;
		node = node->next;
	}
	last = node;
	last->next = head;
	*lst = last;
	prev->next = NULL;
}

void	rra(t_stack **a, int is_valid)
{
	rrotate_func(a);
	if (is_valid)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int is_valid)
{
	rrotate_func(b);
	if (is_valid)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int is_valid)
{
	rra(a, 0);
	rrb(b, 0);
	if (is_valid)
		write(1, "rrr\n", 4);
}

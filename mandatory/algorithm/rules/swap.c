/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:22 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:35:30 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_func(t_stack **lst)
{
	t_stack	*curnt;
	t_stack	*next;

	if (!*lst || !(*lst)->next)
		return ;
	curnt = *lst;
	next = (*lst)->next;
	curnt->next = next->next;
	next->next = curnt;
	curnt = next;
	*lst = curnt;
}

void	sa(t_stack **a, int is_valid)
{
	swap_func(a);
	if (is_valid)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int is_valid)
{
	swap_func(b);
	if (is_valid)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int is_valid)
{
	sa(a, 0);
	sb(b, 0);
	if (is_valid)
		write(1, "ss\n", 3);
}

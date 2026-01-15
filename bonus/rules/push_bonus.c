/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:30 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:22:54 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push_func(t_stack **dest, t_stack **lst)
{
	t_stack	*dst_head;
	t_stack	*lst_head;

	if (!*lst)
		return ;
	dst_head = *lst;
	lst_head = (*lst)->next;
	dst_head->next = *dest;
	*dest = dst_head;
	*lst = lst_head;
}

void	pa(t_stack **a, t_stack **b, int is_valid)
{
	push_func(a, b);
	if (is_valid)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int is_valid)
{
	push_func(b, a);
	if (is_valid)
		write(1, "pb\n", 3);
}

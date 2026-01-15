/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:17:27 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/31 10:13:14 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate_func(t_stack **lst)
{
	t_stack	*node;
	t_stack	*head;
	t_stack	*second;

	if (!*lst || !(*lst)->next)
		return ;
	node = *lst;
	head = *lst;
	second = (*lst)->next;
	while (node->next)
		node = node->next;
	node->next = head;
	head->next = NULL;
	*lst = second;
}

void	ra(t_stack **a, int is_valid)
{
	rotate_func(a);
	if (is_valid)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int is_valid)
{
	rotate_func(b);
	if (is_valid)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int is_valid)
{
	ra(a, 0);
	rb(b, 0);
	if (is_valid)
		write(1, "rr\n", 3);
}

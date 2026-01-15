/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:27 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 18:32:10 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addback(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
}

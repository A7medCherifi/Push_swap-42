/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addback_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:27 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 16:14:45 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

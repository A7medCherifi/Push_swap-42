/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indexes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:57 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:23:45 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	assign_indexes(t_stack *lst)
{
	int		i;
	t_stack	*curnt;
	t_stack	*head;

	head = lst;
	while (lst)
	{
		i = 0;
		curnt = head;
		while (curnt)
		{
			if (lst->value > curnt->value)
				i++;
			curnt = curnt->next;
		}
		lst->index = i;
		lst = lst->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:26:42 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/01 10:38:22 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	size;

	size = lst_size(a);
	if (!a || size == 1)
		return (1);
	while (size > 0)
	{
		if (a->next && a->index < a->next->index)
			a = a->next;
		else if (!a->next)
			return (1);
		else
			return (0);
		size--;
	}
	return (1);
}

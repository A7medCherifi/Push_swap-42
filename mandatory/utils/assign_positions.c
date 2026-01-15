/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:51 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 18:32:51 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->position = i;
		lst = lst->next;
		i++;
	}
}

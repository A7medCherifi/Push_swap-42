/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:11:56 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/27 09:11:59 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

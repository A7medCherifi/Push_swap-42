/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:21 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:18 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	lst_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

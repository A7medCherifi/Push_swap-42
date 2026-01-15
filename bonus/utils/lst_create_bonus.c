/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:24 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:26:05 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*lst_create(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

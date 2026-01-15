/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:49 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:24:14 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:09 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/05 17:21:34 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**array;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	array = NULL;
	if (ac == 1)
		return (0);
	array = create_array(av, ac, array);
	if (!array)
		return (1);
	if (!create_stack(&a, array))
		return (free_array(array), 1);
	free_array(array);
	assign_indexes(a);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	push_stack_b(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

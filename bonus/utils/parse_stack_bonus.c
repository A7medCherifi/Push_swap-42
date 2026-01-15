/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:12:34 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:43:35 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

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

static int	execute_instructions(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n"))
		return (sa(a, 0), 1);
	else if (ft_strcmp(line, "sb\n"))
		return (sb(b, 0), 1);
	else if (ft_strcmp(line, "ss\n"))
		return (ss(a, b, 0), 1);
	else if (ft_strcmp(line, "pa\n"))
		return (pa(a, b, 0), 1);
	else if (ft_strcmp(line, "pb\n"))
		return (pb(b, a, 0), 1);
	else if (ft_strcmp(line, "ra\n"))
		return (ra(a, 0), 1);
	else if (ft_strcmp(line, "rb\n"))
		return (rb(b, 0), 1);
	else if (ft_strcmp(line, "rr\n"))
		return (rr(a, b, 0), 1);
	else if (ft_strcmp(line, "rra\n"))
		return (rra(a, 0), 1);
	else if (ft_strcmp(line, "rrb\n"))
		return (rrb(b, 0), 1);
	else if (ft_strcmp(line, "rrr\n"))
		return (rrr(a, b, 0), 1);
	return (0);
}

void	parse_stack_a(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_instructions(line, a, b))
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	assign_indexes(*a);
}

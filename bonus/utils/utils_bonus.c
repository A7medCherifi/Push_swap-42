/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:15 by acherifi          #+#    #+#             */
/*   Updated: 2026/01/10 10:53:15 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_duplicates(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

char	**create_array(char **av, int ac, char **array)
{
	char	*str;
	char	*temp;
	int		i;

	i = 1;
	str = NULL;
	while (i < ac)
	{
		if (!av[i] || ft_isspace(av[i]))
			return (write(2, "Error\n", 6), free(str), NULL);
		temp = str;
		str = ft_strjoin(str, av[i], ft_strlen(av[i]));
		free(temp);
		if (!str)
			return (write(2, "Error\n", 6), NULL);
		i++;
	}
	array = ft_split(str, ' ');
	free(str);
	if (!array || check_duplicates(array))
		return (write(2, "Error\n", 6), free_array(array), NULL);
	return (array);
}

char	*check_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	return (&str[i]);
}

int	process_argument(t_stack **lst, char *array)
{
	t_stack	*node;
	int		value;

	if (!my_isdigit(array))
		return (0);
	value = ft_atoi(array);
	array = check_zero(array);
	if (value == -1 && ft_strlen(array) != 1)
		return (0);
	node = lst_create(value);
	if (!node)
		return (0);
	lst_addback(lst, node);
	return (1);
}

int	create_stack(t_stack **lst, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!process_argument(lst, array[i]))
			return (free_stack(lst), write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

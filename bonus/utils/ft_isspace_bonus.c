/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:42 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 16:16:46 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

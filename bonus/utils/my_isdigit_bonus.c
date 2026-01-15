/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isdigit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:18 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:26:36 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	my_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:38 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:06 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_numlen(int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

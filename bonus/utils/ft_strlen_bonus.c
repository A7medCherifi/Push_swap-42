/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:29 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/27 09:12:22 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

ssize_t	ft_strlen(char const *s)
{
	ssize_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

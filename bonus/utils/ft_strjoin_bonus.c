/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 09:16:32 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/26 16:20:12 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static ssize_t	my_strlen(char const *s)
{
	ssize_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static void	add_to_str(char *str, char const *s, ssize_t start, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		str[start] = s[i];
		start++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2, ssize_t len)
{
	char	*str;
	ssize_t	s1_len;
	ssize_t	start;

	start = 0;
	s1_len = 0;
	if (!s2)
		return (NULL);
	if (s1)
		s1_len = my_strlen(s1);
	str = malloc(s1_len + len + 2);
	if (!str)
		return (NULL);
	if (s1)
		add_to_str(str, s1, start, s1_len);
	start = s1_len;
	add_to_str(str, s2, start, len);
	str[s1_len + len] = ' ';
	str[s1_len + len + 1] = '\0';
	return (str);
}

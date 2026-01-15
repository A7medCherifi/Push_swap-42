/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:06:04 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/27 09:13:14 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*handle_empty(void)
{
	char	*str;

	str = malloc(1);
	if (str)
		str[0] = '\0';
	return (str);
}

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
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

char	*my_strjoin(char const *s1, char const *s2, ssize_t len)
{
	char	*str;
	ssize_t	s1_len;
	ssize_t	start;

	start = 0;
	s1_len = 0;
	if (!s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	str = malloc(s1_len + len + 1);
	if (!str)
		return (NULL);
	if (s1)
		add_to_str(str, s1, start, s1_len);
	start = s1_len;
	add_to_str(str, s2, start, len);
	str[s1_len + len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, ssize_t start, ssize_t len)
{
	ssize_t	i;
	ssize_t	s_len;
	ssize_t	actual_len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (handle_empty());
	actual_len = s_len - start;
	if (len < actual_len)
		actual_len = len;
	str = malloc(actual_len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < actual_len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

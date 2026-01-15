/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherifi <acherifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:06:22 by acherifi          #+#    #+#             */
/*   Updated: 2025/12/28 16:43:33 by acherifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	declare_var(ssize_t *len, char **storage)
{
	*storage = NULL;
	*len = 0;
}

static char	*fill_line(char **line, char **storage, char **left, ssize_t len)
{
	*line = ft_substr(*storage, 0, len + 1);
	if (!(*line))
		return (free(*storage), NULL);
	if (len + 1 < ft_strlen(*storage))
		*left = ft_substr(*storage, len + 1, ft_strlen(*storage));
	return (free(*storage), *line);
}

static char	*fill_storage(int fd, char *storage, char *buffer, ssize_t *len)
{
	ssize_t	readed;
	char	*temp;

	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (free(storage), NULL);
		if (readed == 0)
		{
			if (storage)
				*len = ft_strchr(storage, '\n');
			if (*len < 0 && storage)
				*len = ft_strlen(storage);
			break ;
		}
		buffer[readed] = '\0';
		temp = storage;
		storage = my_strjoin(storage, buffer, readed);
		free(temp);
		*len = ft_strchr(storage, '\n');
		if (*len >= 0)
			break ;
	}
	return (storage);
}

static char	*check_left(char **left, char *storage)
{
	if (*left)
	{
		storage = my_strjoin(storage, *left, ft_strlen(*left));
		free(*left);
		*left = NULL;
		if (!storage)
			return (NULL);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*buffer;
	char		*line;
	char		*storage;
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(left), left = NULL, NULL);
	declare_var(&len, &storage);
	if (left)
	{
		storage = check_left(&left, storage);
		if (!storage)
			return (NULL);
	}
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(left), left = NULL, NULL);
	storage = fill_storage(fd, storage, buffer, &len);
	free(buffer);
	if (!storage)
		return (NULL);
	if (len >= 0)
		return (fill_line(&line, &storage, &left, len));
	return (storage);
}

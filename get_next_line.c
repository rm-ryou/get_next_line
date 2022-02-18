/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:13:38 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/18 19:33:03 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *save)
{
	char	*buff;
	int		res;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	res = read(fd, buff, BUFFER_SIZE);
	while (res != 0)
	{
		if (res == -1)
			break ;
		buff[res] = '\0';
		save = ft_free_and_strjoin(save, buff);
		if (ft_strchr(save, '\n'))
			break ;
		res = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (save);
}

static char	*ft_get_line(char *save, char *ptr)
{
	char	*line;
	size_t	i;

	if (ft_strlen(save) > 0)
	{
		if (ptr != NULL)
		{
			*ptr = '\0';
			i = ft_strlen(save);
			line = ft_strdup(save);
			if (line == NULL)
				return (NULL);
			line[i] = '\n';
			line[i + 1] = '\0';
		}
		else
			line = ft_strdup(save);
		return (line);
	}
	else
		return (NULL);
}

static char	*ft_save_next_line(char *save, char *ptr)
{
	char	*tmp;

	if (ptr != NULL)
		tmp = ft_strdup(ptr + 1);
	else
		tmp = NULL;
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	save = ft_read_line(fd, save);
	if (save == NULL)
		return (NULL);
	ptr = ft_strchr(save, '\n');
	line = ft_get_line(save, ptr);
	if (line == NULL)
	{
		free(save);
		return (NULL);
	}
	save = ft_save_next_line(save, ptr);
	return (line);
}

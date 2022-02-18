/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:13:38 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/18 16:59:36 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read_line(int fd, char *save)
{
    char    *buff;
    char    *tmp;
    int     res;

    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    res = read(fd, buff, BUFFER_SIZE);
    while (res != 0)
    {
        if (res == -1)
            break;
        buff[res] = '\0';
        tmp = ft_strjoin(save, buff);
        free(save);
        save = tmp;
        if (ft_strchr(save, '\n'))
            break ;
        res = read(fd, buff, BUFFER_SIZE);
    }
    free(buff);
    return (save);
}

char    *ft_get_line(char *save, char *ptr)
{
    char    *line;
    char    *tmp;
    size_t  i;

    if (ptr != NULL)
    {
        *ptr = '\0';
        i = ft_strlen(save);
        line = ft_strdup(save);
        line[i] = '\n';
        line[i + 1] = '\0';
    }
    else
        line = ft_strdup(save);
    return (line);
}

char    *ft_save_next_line(char *save, char *ptr)
{
    char    *tmp;

    if (ptr != NULL)
        tmp = ft_strdup(ptr + 1);
    else
        tmp = NULL;
    free(save);
    return tmp;
}

char    *get_next_line(int fd)
{
    static char *save;
    char        *line;
    char        *tmp;
    char        *ptr;

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
    /*if (ptr != NULL)
        tmp = ft_strdup(ptr + 1);
    else
        tmp = NULL;
    free(save);
    save = tmp;*/
    return (line);
}
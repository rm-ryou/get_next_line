/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:13:46 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/18 15:53:11 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  len;

    len = 0;
    if (s == NULL)
        return (0);
    while (s[len] != '\0')
        len++;
    return (len);
}

char    *ft_strchr(const char *s, int c)
{
    size_t  i;

    i = 0;
    if (s == NULL)
        return (NULL);
    while (s[i] != c)
    {
        if (s[i] == '\0')
            return (NULL);
        i++;
    }
    return ((char *)&s[i]);
}

char    *ft_strdup(const char *s1)
{
    char    *res;
    size_t  i;

    i = 0;
    if (s1 == NULL)
        return (NULL);
    res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (res == NULL)
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (s1 == NULL)
        s1 = ft_strdup("");
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (str == NULL)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}
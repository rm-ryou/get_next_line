/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:14:26 by rmoriya           #+#    #+#             */
/*   Updated: 2022/02/18 19:15:07 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int     fd;
    char    *line;

    fd = open("file1.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
    }
	free(line);
    close(fd);
    return (0);
}

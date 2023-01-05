/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:12:22 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/05 14:55:43 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save_map(t_var *var)
{
    int fd = open("firstmap", O_RDONLY);
    char *line;
    char *join_lines = NULL;

    line = get_next_line(fd);
    while (line){
        join_lines = ft_strjoin(join_lines, line);
        free(line);
        line = get_next_line(fd);
    }
    var->map = ft_split(join_lines, '\n');
    free(join_lines);
}

void get_cords(t_var *var)
{
    int i;
    int j;

    j = 0;
    while (var->map[j])
    {
        i = 0;
        while (var->map[j][i])
        {
            if (var->map[j][i] == '3')
            {
                var->player_y = j + 0.5;
                var->player_x = i + 0.5;
                var->map[j][i] = '0';
            }
            i++;
        }
        j++;
    }
}

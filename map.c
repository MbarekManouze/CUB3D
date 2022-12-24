/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:12:22 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/22 23:06:16 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int render_rect(t_var *var, int y, int x, int color)
{
	int	i;
	int j;

	i = y;
	while (i < y + (SCALE * DIMENSION) - 1)
	{
		j = x;
		while (j < x + (SCALE * DIMENSION) - 1){
			my_mlx_pixel_put(var, j, i, color);
            j++;
        }
		i++;
	}
	return (0);
}

void draw_2d_map(t_var *var)
{
    int i = 0;
    int j = 0;
    while (var->map[i] != NULL)
    {
        while (var->map[i][j])
        {
            if (var->map[i][j] == '1')
                render_rect(var, SCALE * j * DIMENSION, SCALE * i * DIMENSION, 0xFFFF00);
            else if (var->map[i][j] == '0')
                render_rect(var, SCALE * j * DIMENSION, SCALE * i * DIMENSION, 0xFFFFFF);
            j++;
        }
        j=0;
        i++;
    }
}

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

    i = 0;
    while (var->map[i])
    {
        j = 0;
        while (var->map[i][j])
        {
            if (var->map[i][j] == '3')
            {
                var->j = i * DIMENSION + 70;//***5
                var->i = j * DIMENSION + 70;//***6
                var->map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}

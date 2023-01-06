/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:10:59 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/06 18:25:03 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	if (x < 0 || x > data->size_x || y < 0 || y > data->size_y)
		return ;
	data->dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)data->dst = color;
}

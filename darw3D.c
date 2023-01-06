/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darw3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:52:15 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/06 18:43:57 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_3d(t_var *var, int abs, int i, double fov)
{
	calcul_indexes(var, abs);
	paint_sky(var, i);
	paint_walls(var, i, fov);
	while (var->index < W_HIGHT)
	{
		my_mlx_pixel_put(var, i, var->index, 0xd4c5ad);
		var->index++;
	}
}

void	calcul_indexes(t_var *var, int abs)
{
	var->P_W_D = (W_WIDTH / 2) / tan(30 * (M_PI / 180));
	var->P_W_H = ((DIMENSION) / (abs * SCALE)) * (var->P_W_D * SCALE);
	var->top_pixel = (W_HIGHT / 2) - ((int)var->P_W_H / 2);
	if (var->top_pixel < 0)
		var->top_pixel = 0;
	var->bottom_pixel = (W_HIGHT / 2) + ((int)var->P_W_H / 2);
	if (var->bottom_pixel > W_HIGHT)
		var->bottom_pixel = W_HIGHT;
}

void	paint_sky(t_var *var, int i)
{
	var->index = 0;
	while (var->index < var->top_pixel)
	{
		my_mlx_pixel_put(var, i, var->index, 0xADD8E6);
		var->index++;
	}
}

void	paint_walls(t_var *var, int i, double fov)
{
	while (var->index < var->bottom_pixel)
	{
		wall_pixels(var, fov);
		my_mlx_pixel_put(var, i, var->index, var->pos);
		var->index++;
	}
}

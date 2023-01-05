/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:09:27 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/05 15:38:05 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void calcul_indexes(t_var *var, int abs)
{
    var->P_W_D = (W_WIDTH / 2) / tan(30 * (M_PI / 180));
    var->P_W_H = ((DIMENSION) / (abs * SCALE)) * (var->P_W_D * SCALE);
    var->top_pixel = (W_HIGHT / 2 ) - ((int)var->P_W_H / 2);
    if(var->top_pixel < 0)
        var->top_pixel = 0;
    var->bottom_pixel = (W_HIGHT / 2) + ((int)var->P_W_H / 2);
    if(var->bottom_pixel > W_HIGHT )
        var->bottom_pixel = W_HIGHT;
}

void x_wall_text(t_var *var, double fov, int line)
{
	if (var->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION] \
	[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1')
        var->x_text = (int)var->Xhitwall % (line / 4);
    else
        var->x_text = (int)var->Yhitwall % (line / 4);
    if (line / 4 > DIMENSION)
        var->x_text = ((int)var->x_text * (line / 4) / DIMENSION % (line / 4));
}

void paint_sky(t_var *var, int i)
{
    var->index = 0;
    while (var->index < var->top_pixel)
    {
        my_mlx_pixel_put(var, i, var->index, 0xADD8E6);
        var->index++;                
    }
}

void wall_pixels(t_var *var, double fov)
{
	if (var->dir == 'N')
	{
		x_wall_text(var, fov, var->line_img_N);
		north_wall(var);
	}
	if (var->dir == 'S')
	{
		x_wall_text(var , fov, var->line_img_S);
		south_wall(var);
	}
	if (var->dir == 'W')
	{
		x_wall_text(var, fov, var->line_img_W);
		west_wall(var);
	}
	if (var->dir == 'E')
	{
		x_wall_text(var,fov, var->line_img_E);
		east_wall(var);
	}
}

void paint_walls(t_var *var, int i, double fov)
{
    while (var->index < var->bottom_pixel)
    {
		wall_pixels(var, fov);
        my_mlx_pixel_put(var, i, var->index, var->pos);
        var->index++;
    }
}

void draw_3D(t_var *var, int abs, int i, double fov)
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

void horizontal_or_vertical(t_var *var, double wall_x, double wall_y, double fov)
{
    var->horizontal = 0;
    var->vertical = 0;
	if (var->map[(int)(wall_y + sin(fov)) / DIMENSION] \
	[(int)(wall_x - cos(fov)) / DIMENSION] == '1')
        var->horizontal = 1;
    else
        var->vertical = 1;
}

void specify_derication(t_var *var, double wall_y, double wall_x)
{
	double	x_pos;
	double	y_pos;

	x_pos = var->player_x * DIMENSION;
	y_pos = var->player_y * DIMENSION;

	if (wall_y >= y_pos && var->horizontal == 1)
		var->dir = 'S';
	if (var->vertical == 1 && wall_x >= x_pos)
		var->dir = 'E';
	if (wall_x <= x_pos && var->vertical == 1)
		var->dir = 'W';
	if (var->horizontal == 1 && wall_y <= y_pos)
		var->dir = 'N';
}

void direction_option(double wall_x, double wall_y, t_var *var, double fov)
{
	horizontal_or_vertical(var, wall_x, wall_y, fov);
	specify_derication(var, wall_y, wall_x);
}

void close_wall(t_var *var, double fov, int i)
{
	while (1)
	{
		var->Xhitwall += cos(fov);
		var->Yhitwall += sin(fov);
		if (var->map[(int)(var->Yhitwall) / DIMENSION]
			[(int)(var->Xhitwall) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall - sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov)) / DIMENSION] == '1')
		{
			direction_option( var->Xhitwall, var->Yhitwall, var, fov);
			double abs = sqrt(pow((var->Xhitwall - (var->player_x \
			* DIMENSION)), 2)+ pow((var->Yhitwall - (var->player_y \
			* DIMENSION)), 2)) * cos(var->pa - fov);
			draw_3D(var, abs, i, fov);
			return ;
		}
	}
}

void far_wall(t_var *var, double fov, int i)
{
	double	yf;
	double	yc;
	int		speed;

	speed = 50;
	while (1)
	{
		var->Xhitwall += cos(fov) * speed;
		var->Yhitwall += sin(fov) * speed;
		yf = sin(fov) * speed;
		yc = sin(fov);
		if (var->map[(int)(var->Yhitwall) / DIMENSION]
			[(int)(var->Xhitwall) / DIMENSION]== '1' 
			|| var->map[(int)(var->Yhitwall + yc + yf) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov) + (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall - yc - yf) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov) + (cos(fov) * speed)) \
			/ DIMENSION] == '1')
			{
				close_wall(var, fov, i);
				return ;
			}
	}
}

void ray_projection(double fov, t_var *var, int i)
{
	var->Xhitwall = var->player_x * DIMENSION;
	var->Yhitwall = var->player_y * DIMENSION;
	far_wall(var, fov, i);
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	player_view(t_var *var)
{
    int		i;
    double	fov;
    
	i = -1;
	fov = var->pa - (30 * (M_PI / 180));
	while (++i < W_WIDTH)
	{
		ray_projection(normalize_angle(fov), var, i);
		fov += (degree_to_radian(60)) / (W_WIDTH);
	}
}

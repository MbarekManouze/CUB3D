/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:09:27 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/24 19:20:04 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drawCircle(t_var *var,int xc, int yc, int x, int y)
{
    my_mlx_pixel_put(var,xc+x, yc+y, 0x0000FF00);
    my_mlx_pixel_put(var,xc-x, yc+y, 0x0000FF00);
    my_mlx_pixel_put(var,xc+x, yc-y, 0x0000FF00);
    my_mlx_pixel_put(var,xc-x, yc-y, 0x0000FF00);
    my_mlx_pixel_put(var,xc+y, yc+x, 0x0000FF00);
    my_mlx_pixel_put(var,xc-y, yc+x, 0x0000FF00);
    my_mlx_pixel_put(var,xc+y, yc-x, 0x0000FF00);
    my_mlx_pixel_put(var,xc-y, yc-x, 0x0000FF00);
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}

void circleBres(t_var *var, int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(var, xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(var, xc, yc, x, y);
    }
}

void draw_3D(t_var *var, int abs, int i)
{
            double P_W_D = (W_WIDTH / 2) / tan(degree_to_radian(30));
            double P_W_H = ((140) / (abs * SCALE)) * (P_W_D * SCALE);
            if (P_W_H > 1400)
                P_W_H = 1400;
            int top_pixel = (W_HIGHT / 2 ) - ((int)P_W_H / 2);
            if(top_pixel < 0)
                top_pixel = 0;
            int bottom_pixel = (W_HIGHT / 2) + ((int)P_W_H / 2);
            if(bottom_pixel > W_HIGHT )
                bottom_pixel = W_HIGHT;
            int index = 0;
            while (index < top_pixel)
            {
                my_mlx_pixel_put(var, i, index, 0xADD8E6);
                index++;                
            }
            index = top_pixel;
            while (index < bottom_pixel - 1)//0x964B00
            {
                my_mlx_pixel_put(var, i, index, var->COLOR);
                index++;
            }
            index = bottom_pixel - 1;
            while (index < W_HIGHT - 1)
            {
                my_mlx_pixel_put(var, i, index, 0xd4c5ad);
                index++;
            }
}

void specify_direction(double wall_x, double wall_y, t_var *var, double fov)
{
    if (var->map[(int)(wall_x + cos(fov))/DIMENSION][(int)(wall_y - sin(fov))/DIMENSION] == '1')
    {
        if (var->hori_direction == 'E')
            var->COLOR = 0xffca7c;
        else
            var->COLOR = 0xce4993;
    }
    else
    {
        if (var->vert_direction == 'N')
            var->COLOR = 0xA5F2F3;
        else
            var->COLOR = 0x228B22;
    }
}

void direction_option(double wall_x, double wall_y, t_var *var, double fov)
{
    if (var->i < wall_x)
        var->hori_direction = 'E';
    else
        var->hori_direction = 'W';

    if (var->j > wall_y)
        var->vert_direction = 'N';
    else
        var->vert_direction = 'S';
    
    specify_direction(wall_x, wall_y, var, fov);
}

void    cast_ray(double fov, t_var *var, int i)
{
    double pdx = var->i;
    double pdy = var->j;
    while (1)
    {
        pdx += cos(fov);
        pdy += sin(fov);
        if (var->map[(int)pdx/DIMENSION][(int)pdy/DIMENSION] == '1' || var->map[(int)(pdx - cos(fov))/DIMENSION][(int)(pdy + sin(fov))/DIMENSION] == '1'
            || var->map[(int)(pdx + cos(fov))/DIMENSION][(int)(pdy - sin(fov))/DIMENSION] == '1')
        {
            double abs = sqrt(pow((pdx - (var->i)), 2) + (pow((pdy - (var->j)),2))) * cos(var->pa - fov);
            direction_option(pdx, pdy, var, fov);
            draw_3D(var, abs, i);
            break ;
        }
        // my_mlx_pixel_put(var, SCALE *pdx, SCALE *pdy, 0xFF0000);
    }
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
    int i = -1;
    double fov = var->pa - (30 * (M_PI / 180));
    while (++i <= var->size_x)
    {
	    cast_ray(normalize_angle(fov), var, i);
	    fov +=(60 * (M_PI / 180)) / (var->size_x);
    }
}

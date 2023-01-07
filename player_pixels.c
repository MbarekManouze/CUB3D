/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:09:27 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/07 15:02:49 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_wall(t_var *var, double fov, int i)
{
	double	abs;

	while (1)
	{
		var->Xhitwall += cos(fov);
		var->Yhitwall += sin(fov);
		if (var->map[(int)(var->Yhitwall) / DIMENSION]
			[(int)(var->Xhitwall) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall - sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov)) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov)) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall - sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1')
		{
			direction_option(var->Xhitwall, var->Yhitwall, var, fov);
			abs = sqrt(pow((var->Xhitwall - (var->player_x \
			* DIMENSION)), 2) + pow((var->Yhitwall - (var->player_y \
			* DIMENSION)), 2)) * cos(var->pa - fov);
			draw_3d(var, abs, i, fov);
			return ;
		}
	}
}

void	far_wall(t_var *var, double fov, int i)
{
	double	yf;
	double	yc;
	int		speed;

	speed = 30;
	while (1)
	{
		var->Xhitwall += cos(fov) * speed;
		var->Yhitwall += sin(fov) * speed;
		yf = sin(fov) * speed;
		yc = sin(fov);
		if (var->map[(int)(var->Yhitwall) / DIMENSION]
			[(int)(var->Xhitwall) / DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall + yc + yf) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov) + (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall - yc - yf) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov) + (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			|| var->map[(int)(var->Yhitwall - yc + yf) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov) - (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			||var->map[(int)(var->Yhitwall + yc - yf) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov) - (cos(fov) * speed)) \
			/ DIMENSION] == '1')
		{
			close_wall(var, fov, i);
			return ;
		}
	}
}

void	ray_projection(double fov, t_var *var, int i)
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

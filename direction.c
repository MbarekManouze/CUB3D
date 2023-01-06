/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:54:16 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/06 18:39:47 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	direction_option(double wall_x, double wall_y, t_var *var, double fov)
{
	horizontal_or_vertical(var, wall_x, wall_y, fov);
	specify_derication(var, wall_y, wall_x);
}

void	horizontal_or_vertical(t_var *var, double wall_x,
double wall_y, double fov)
{
	var->horizontal = 0;
	var->vertical = 0;
	if (var->map[(int)(wall_y + sin(fov)) / DIMENSION] \
	[(int)(wall_x - cos(fov)) / DIMENSION] == '1')
		var->horizontal = 1;
	else
		var->vertical = 1;
}

void	specify_derication(t_var *var, double wall_y, double wall_x)
{
	double	x_pos;
	double	y_pos;

	x_pos = var->player_x * DIMENSION;
	y_pos = var->player_y * DIMENSION;
	if (wall_y >= y_pos && var->horizontal == 1)
		var->direction = 'S';
	if (var->vertical == 1 && wall_x >= x_pos)
		var->direction = 'E';
	if (wall_x <= x_pos && var->vertical == 1)
		var->direction = 'W';
	if (var->horizontal == 1 && wall_y <= y_pos)
		var->direction = 'N';
}

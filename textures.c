/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:53:32 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/06 18:24:14 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_pixels(t_var *var, double fov)
{
	if (var->direction == 'N')
	{
		x_wall_text(var, fov, var->line_img_N);
		north_wall(var);
	}
	if (var->direction == 'S')
	{
		x_wall_text(var, fov, var->line_img_S);
		south_wall(var);
	}
	if (var->direction == 'W')
	{
		x_wall_text(var, fov, var->line_img_W);
		west_wall(var);
	}
	if (var->direction == 'E')
	{
		x_wall_text(var, fov, var->line_img_E);
		east_wall(var);
	}
}

void	x_wall_text(t_var *var, double fov, int line)
{
	if (var->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION] \
	[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1')
		var->x_text = (int)var->Xhitwall % (line / 4);
	else
		var->x_text = (int)var->Yhitwall % (line / 4);
	if (line / 4 > DIMENSION)
		var->x_text = ((int)var->x_text * (line / 4) / DIMENSION % (line / 4));
}

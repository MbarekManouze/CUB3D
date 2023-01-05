/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:13:47 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/05 18:27:38 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_turn_right(t_var *var)
{
	var->pa += (10 * (M_PI / 180));
	if (var->pa > 2 * M_PI)
		var->pa = remainder(var->pa, M_PI * 2);
}

void ft_turn_left(t_var *var)
{
	var->pa -= (10 * (M_PI / 180));
	if (var->pa < 0)
		var->pa += 2 * M_PI;
}

void ft_right(t_var *var)
{
    var->DeltaY = sin((var->pa + (M_PI / 2))) * (-SPEED - (SIGHT_SPEED));
    var->DeltaX = cos((var->pa + (M_PI / 2))) * (-SPEED - (SIGHT_SPEED));
	if (var->map[(int)(var->player_y - var->DeltaY)] \
	[(int)(var->player_x - var->DeltaX)] != '0')
		return ;
	var->player_x -= var->DeltaX;
	var->player_y -= var->DeltaY;
}

void ft_left(t_var *var)
{
    var->DeltaX = cos((var->pa - (M_PI / 2))) * (SPEED + SIGHT_SPEED);
    var->DeltaY = sin((var->pa - (M_PI / 2))) * (SPEED + SIGHT_SPEED);
	if (var->map[(int)(var->player_y + var->DeltaY)] \
	[(int)(var->player_x + var->DeltaX)] == '0')
	{
    	var->player_y += var->DeltaY;
	    var->player_x += var->DeltaX;
	}
}

void ft_up(t_var *var)//up
{
	printf("ok\n");
	var->DeltaX = cos(var->pa) * (SPEED + (SIGHT_SPEED));
	var->DeltaY = sin(var->pa) * (SPEED + (SIGHT_SPEED));
	if (var->map[(int)(var->player_y + var->DeltaY)] \
	[(int)(var->player_x + var->DeltaX)] != '0')
		return ;
	var->player_x += var->DeltaX;
	var->player_y += var->DeltaY;
}

void ft_down(t_var *var)//down
{
	var->DeltaX = cos(var->pa) * (SPEED + (SIGHT_SPEED));
	var->DeltaY = sin(var->pa) * (SPEED + (SIGHT_SPEED));
	if (var->map[(int)(var->player_y - var->DeltaY)] \
	[(int)(var->player_x - var->DeltaX)] != '0')
		return ;
	var->player_x -= var->DeltaX;
	var->player_y -= var->DeltaY;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:13:47 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/23 15:32:01 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_turn_right(t_var *var)
{
    var->pa = var->pa + (5 * (M_PI / 180));
    if (var->pa >= 360)
        var->pa = 0;
}

void ft_turn_left(t_var *var)
{
    var->pa = var->pa - (5 * (M_PI / 180));
    if (var->pa <= 0)
        var->pa = M_PI*2;//***
}

void ft_right(t_var *var)
{
    if (var->map[(int)(var->i - cos((var->pa - (M_PI/2))) * SPEED) / DIMENSION][(int)(var->j - sin((var->pa - (M_PI/2))) * SPEED) / DIMENSION] == '1')
        return ;
    var->i -= cos((var->pa - (M_PI/2))) * SPEED;
    var->j -= sin((var->pa - (M_PI/2))) * SPEED; 
}

void ft_left(t_var *var)
{
    if (var->map[(int)(var->i + cos((var->pa - (M_PI/2))) * SPEED) / DIMENSION][(int)(var->j + sin((var->pa - (M_PI/2))) * SPEED) / DIMENSION] == '1')
        return ;
    var->i += cos((var->pa - (M_PI/2))) * SPEED;
    var->j += sin((var->pa - (M_PI/2))) * SPEED; 
}

void ft_down(t_var *var)
{
    if (var->map[(int)(var->i +cos(var->pa) * SPEED) / DIMENSION][(int)(var->j + sin(var->pa) * SPEED) / DIMENSION] == '1')
        return ;
    var->i += cos(var->pa) * SPEED;
    var->j += sin(var->pa) * SPEED;
}

void ft_up(t_var *var)
{
    if (var->map[(int)(var->i - cos(var->pa) * SPEED) / DIMENSION][(int)(var->j - sin(var->pa) * SPEED) / DIMENSION] == '1')
        return ;
    var->i -= cos(var->pa) * SPEED;
    var->j -= sin(var->pa) * SPEED;
}

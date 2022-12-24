/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiliaze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:16:40 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/22 22:56:53 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void initiliaze(t_var *var)
{
    var->size_x = W_WIDTH; //1400 / 70 (70 * 20)
    var->size_y = W_HIGHT; 
    var->pa = degree_to_radian(270);
    // printf("pa --> %f\n" ,var->pa);
    // var->pdx = cos(degree_to_radian(var->pa)) * 10;
    // var->pdy = sin(degree_to_radian(var->pa)) * 10;
    var->mlx = mlx_init();
    var->win = mlx_new_window(var->mlx, var->size_x, var->size_y, "CUB3D");
	var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
    var->key_A_D = -1;
    var->key_R_L = -1;
    var->key_U_D = -1;
    var->key_W_S = -1;
}

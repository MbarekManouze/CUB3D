/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiliaze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:16:40 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:20 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initiliaze(t_var *var)
{
	int	i;

	var->key_A_D = -1;
	var->key_R_L = -1;
	var->key_U_D = -1;
	var->key_W_S = -1;
	var->mlx = mlx_init();
	var->size_x = W_WIDTH;
	var->size_y = W_HIGHT;
	var->pa = degree_to_radian(180);
	var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->win = mlx_new_window(var->mlx, var->size_x, var->size_y, "CUB3D");
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
	var->img_text_N = mlx_xpm_file_to_image(var->mlx,
			"./textures/grey-wall.xpm", &i, &i);
	var->addr_img_N = mlx_get_data_addr(var->img_text_N,
			&var->bits_img, &var->line_img_N, &var->endian_img);
	var->img_text_S = mlx_xpm_file_to_image(var->mlx,
			"./textures/wall.xpm", &i, &i);
	var->addr_img_S = mlx_get_data_addr(var->img_text_S,
			&var->bits_img, &var->line_img_S, &var->endian_img);
	var->img_text_E = mlx_xpm_file_to_image(var->mlx,
			"./textures/wally.xpm", &i, &i);
	var->addr_img_E = mlx_get_data_addr(var->img_text_E,
			&var->bits_img, &var->line_img_E, &var->endian_img);
	var->img_text_W = mlx_xpm_file_to_image(var->mlx,
			"./textures/7ayt.xpm", &i, &i);
	var->addr_img_W = mlx_get_data_addr(var->img_text_W,
			&var->bits_img, &var->line_img_W, &var->endian_img);
}

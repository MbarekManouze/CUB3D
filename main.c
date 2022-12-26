/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:59:11 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/26 15:37:21 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
    t_var *var;
    int i;
    int j;

    var = (t_var *)malloc(sizeof(t_var));
    save_map(var);
    initiliaze(var);
    get_cords(var);
    mlx_hook(var->win, 2, 0, key_down, var);
    mlx_hook(var->win, 3, 0, key_up, var);
    var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
    var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
    var->img_text = mlx_xpm_file_to_image(var->mlx, "./leila.xpm", &i, &j);
    var->addr_img = mlx_get_data_addr(var->img_text, &var->bits_img, &var->line_img, &var->endian_img);
    // key_manager(var);
    mlx_loop_hook(var->mlx, loop_event, var);
    mlx_loop(var->mlx);
}
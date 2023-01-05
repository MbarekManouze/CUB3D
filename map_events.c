/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:17:39 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/05 18:27:25 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int loop_event(t_var *var)
{
    // mlx_destroy_image(var->mlx, var->img);
    // var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
    // var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length, &var->endian);
    key_manager(var);
    player_view(var);
    mlx_put_image_to_window(&var, var->win, var->img, 0, 0);
    return (0);
}

int    reset_keys(int key, t_var *var)
{
    if (key == 0 || key == 2)
        var->key_A_D = -1;
    if (key == 1 || key == 13)
        var->key_W_S = -1;
    if (key == 123 || key == 124)
        var->key_R_L = -1;
    if (key == 126 || key == 125)
        var->key_U_D = -1;
    return (0);
}

int    initiliaze_keys(int key, t_var *var)
{
    if (key == 0 )
        var->key_A_D = key;
    else if (key == 2)
        var->key_A_D = key;
    if (key == 1 )
        var->key_W_S = key;
    else if (key == 13)
        var->key_W_S = key;
    if (key == 123 )
        var->key_R_L = key;
    else if (key == 124)
        var->key_R_L = key;
    if (key == 126)
        var->key_U_D = key;
    else if (key == 125)
        var->key_U_D = key;
    else if(key == 53)
    {
        free(var);
        exit(0);
    }
    return (0);
}

int    key_manager(t_var *var)
{
    if (var->key_A_D == 0 )
         ft_left(var);
    else if (var->key_A_D == 2)
         ft_right(var);
    if (var->key_W_S == 1 )
        ft_up(var);
    else if (var->key_W_S == 13)
        ft_down(var);
    if (var->key_R_L == 123 )
        ft_turn_left(var);
    else if (var->key_R_L == 124)
        ft_turn_right(var);
    if (var->key_U_D == 126)
        ft_up(var);
    else if (var->key_U_D == 125)
        ft_down(var);
    return (0);
}
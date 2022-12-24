/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:59:11 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/24 15:27:30 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
    t_var *var;

    var = (t_var *)malloc(sizeof(t_var));
    save_map(var);
    initiliaze(var);
    get_cords(var);
    mlx_hook(var->win, 2, 0, key_down, var);
    mlx_hook(var->win, 3, 0, key_up, var);
    mlx_loop_hook(var->mlx, loop_event, var);
    mlx_loop(var->mlx);
}
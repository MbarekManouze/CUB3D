/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:59:11 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/06 18:30:56 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	save_map(var);
	initiliaze(var);
	get_cords(var);
	mlx_hook(var->win, 2, 0, initiliaze_keys, var);
	mlx_hook(var->win, 3, 0, reset_keys, var);
	mlx_loop_hook(var->mlx, loop_event, var);
	mlx_loop(var->mlx);
	return (0);
}

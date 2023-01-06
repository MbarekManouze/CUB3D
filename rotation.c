/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:57:51 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/06 18:21:44 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turn_right(t_var *var)
{
	var->pa += (10 * (M_PI / 180));
	if (var->pa > 2 * M_PI)
		var->pa = remainder(var->pa, M_PI * 2);
}

void	ft_turn_left(t_var *var)
{
	var->pa -= (10 * (M_PI / 180));
	if (var->pa < 0)
		var->pa += 2 * M_PI;
}

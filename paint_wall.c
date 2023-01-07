/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:51:53 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/07 15:07:14 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// we add the to index the (P_W_H / 2) - (W_HIGHT / 2)
// to get the exact Y coordinate of where the pixel should be represented. 
// (FIXED_POINT is a Y coordinate of the window)

// we devide var->line_img_* by 4 soo we don't skip any pixel at all ,
// and we multiply it by var->y_text to go diractley to the pixel we need.

// the equation ((double)(var->line_img_N / 4) / var->P_W_H) 
// gives a little factor which we multiply by var->FIXED_POINT to get the 

void	north_wall(t_var *var)
{
	var->Fixed_point = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->Fixed_point * ((double)(var->line_img_N / 4)
			/ var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_N + var->y_text
			* (var->line_img_N / 4) + var->x_text);
}

void	south_wall(t_var *var)
{
	var->Fixed_point = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->Fixed_point * ((double)(var->line_img_S / 4)
			/ var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_S + var->y_text
			* (var->line_img_S / 4) + var->x_text);
}

void	west_wall(t_var *var)
{
	var->Fixed_point = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->Fixed_point * ((double)(var->line_img_W / 4)
			/ var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_W + var->y_text
			* (var->line_img_W / 4) + var->x_text);
}

void	east_wall(t_var *var)
{
	var->Fixed_point = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->Fixed_point * ((double)(var->line_img_E / 4)
			/ var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_E + var->y_text
			* (var->line_img_E / 4) + var->x_text);
}

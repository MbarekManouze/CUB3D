/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:51:53 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/05 14:51:34 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void north_wall(t_var *var)
{
	var->dist = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->dist * ((double)(var->line_img_N / 4) / var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_N + var->y_text * (var->line_img_N / 4) + var->x_text);
}

void south_wall(t_var *var)
{

	var->dist = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->dist * ((double)(var->line_img_S / 4) / var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_S + var->y_text * (var->line_img_S / 4) + var->x_text);
}

void west_wall(t_var *var)
{

	var->dist = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->dist * ((double)(var->line_img_W / 4) / var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_W + var->y_text * (var->line_img_W / 4) + var->x_text);
}

void east_wall(t_var *var)
{

	var->dist = var->index + (var->P_W_H / 2) - (W_HIGHT / 2);
	var->y_text = var->dist * ((double)(var->line_img_E / 4) / var->P_W_H);
	var->pos = *((unsigned int *)var->addr_img_E + var->y_text * (var->line_img_E / 4) + var->x_text);
}

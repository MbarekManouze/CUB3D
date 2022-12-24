/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:59:11 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/10 11:53:29 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawCircle(t_var *var,int xc, int yc, int x, int y)
{
    my_mlx_pixel_put(var,xc+x, yc+y, 0x0000FF00);
    my_mlx_pixel_put(var,xc-x, yc+y, 0x0000FF00);
    my_mlx_pixel_put(var,xc+x, yc-y, 0x0000FF00);
    my_mlx_pixel_put(var,xc-x, yc-y, 0x0000FF00);
    my_mlx_pixel_put(var,xc+y, yc+x, 0x0000FF00);
    my_mlx_pixel_put(var,xc-y, yc+x, 0x0000FF00);
    my_mlx_pixel_put(var,xc+y, yc-x, 0x0000FF00);
    my_mlx_pixel_put(var,xc-y, yc-x, 0x0000FF00);
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}

void	cast_ray(double fov, t_var *var)
{
    // var->pdx = var->j;
    // var->pdy = var->i;
    double pdx = var->j;
    double pdy = var->i;
    int l = 0;
    // mlx_clear_window(var->mlx, var->win);
    while (l < 30)
    {
        pdx += cos(fov) * 5;
        pdy += sin(fov) * 5;
    // printf("pdx : %f\n", pdx);
    // printf("pdy : %f\n", pdy);

        // // Protect you self (Seg Fault)
        // if (var->map[(int)var->pdx][(int)var->j] == '1' || var->map[(int)var->i + 1][(int)var->j + 1] == '1' || var->map[(int)var->i - 1][(int)var->j - 1] == '1')
        //     break ;
        // if (var->map[(int)pdx][(int)pdy] == '1')
	    //     break ;
        my_mlx_pixel_put(var, pdx, pdy, 0xFF0000);
        l++;
    }
}

void	player_view(t_var *var)
{
    int i = -1;
    double fov = var->pa - 30;
    while (++i < 50)
    {
	    cast_ray(fov, var);
	    fov += 0.0333;
    }
}

int render_rect(t_var *var, int y, int x, int color)
{
	int	i;
	int j;

	i = y;
    // printf("index : %d\n", y);
	while (i < y + 98 -1)
	{
		j = x;
		while (j < x + 140-1){
			my_mlx_pixel_put(var, j, i, color);
            j++;
        }
		++i;
	}
	return (0);
}

void draw_2d_map(t_var *var)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;

    while (var->map[i] != NULL)
    {
        while (var->map[i][j])
        {
            if (var->map[i][j] == '1')
                render_rect(var, y, x, 0xFFFF00);
            else if (var->map[i][j] == '0')
                render_rect(var, y, x, 0xFFFFFF);
            else if (var->map[i][j] == '3')
                render_rect(var, y, x, 0xFFFFFF);
            j++;
            x += 140;
        }
        j=0;
        i++;
        x=0;
        y += 98;
    }
}

void circleBres(t_var *var, int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(var, xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(var, xc, yc, x, y);
    }
}

void ft_right(t_var *var){
    mlx_destroy_image(var->mlx, var->img);
    var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
    var->pa -= 0.5;
    if (var->pa <= 0)
        var->pa = 90;
    var->j -= 5;
    // if (var->pa >= 2*PI)
    // {
    //     var->pa -= 2 * PI;
    // }
    // var->pdx = cos(var->pa);
    // var->pdy = sin(var->pa); 
    draw_2d_map(var);
    player_view(var);
    circleBres(var, var->j, var->i, 10);
}

void ft_left(t_var *var){
    mlx_destroy_image(var->mlx, var->img);
    var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
    var->pa += 0.5;
    if (var->pa >= 180)
        var->pa = 90;
    var->j += 5;
    // if (var->pa <= 0)
    // {
    //     var->pa += 2 * PI;
    // }
    // var->pdx = cos(var->pa);
    // var->pdy = sin(var->pa); 
    draw_2d_map(var);
    player_view(var);
    circleBres(var, var->j, var->i, 10);
}

void ft_down(t_var *var){
    mlx_destroy_image(var->mlx, var->img);
    var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
    var->i -= 5;
    // var->i -= var->pdx - 10; 
    // var->j -= var->pdy - 10; 
    // var->i -= var->pdx;
    // var->j += var->pdy;
    draw_2d_map(var);
    player_view(var);
    circleBres(var, var->j, var->i, 10);
}

void ft_up(t_var *var){
    mlx_destroy_image(var->mlx, var->img);
    var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
    var->i += 5;
    // var->i += var->pdx - 10; 
    // var->j += var->pdy - 10; 
    // var->i += var->pdx;
    // var->j += var->pdy;

    draw_2d_map(var);
    player_view(var);
    circleBres(var, var->j, var->i, 10);
}

int	key_manager(int key, t_var *var)
{
	if (key == 53)
		exit (0);
    if (key == 124 || key == 2)
    {
        ft_right(var);
    }
    if (key == 0 || key == 123){
        ft_left(var);
    }
    if (key == 126 || key == 13){
        ft_down(var);
    }
    if (key == 125 || key == 1){
        ft_up(var);
    }
	return (0);
}


void initiliaze(t_var *var){

    var->size_x = 20 * 70; //1400 / 70 (70 * 20)
    var->size_y = 14 * 70; 
    // var->i = 500;
    // var->j = 500;
    var->pa = 90;
    var->pdx = cos(var->pa);
    var->pdy = sin(var->pa);
    var->mlx = mlx_init();
    var->win = mlx_new_window(var->mlx, var->size_x, var->size_y, "CUB3D");
	var->img = mlx_new_image(var->mlx, var->size_x, var->size_y);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,&var->endian);
}

void save_map(t_var *var){
    int fd = open("firstmap", O_RDONLY);
    char *line;
    char *join_lines = NULL;

    line = get_next_line(fd);
    while (line){
        join_lines = ft_strjoin(join_lines, line);
        free(line);
        line = get_next_line(fd);
    }
    var->map = ft_split(join_lines, '\n');
    free(join_lines);
}

void get_cords(t_var *var)
{
    int i;
    int j;

    i = 0;
    while (var->map[i])
    {
        j = 0;
        while (var->map[i][j])
        {
            if (var->map[i][j] == '3')
            {
                // printf("inside i : %d\n", i * 70);
                // printf("inside j : %d\n", j * 70);
                var->i = i * 70;
                var->j = j * 70;
            }
            j++;
        }
        i++;
    }
}

int main(){
    t_var var;


    save_map(&var);
    get_cords(&var);
    initiliaze(&var);
    // system("leaks a.out");
    draw_2d_map(&var);
    // mlx_put_image_to_window(var.mlx, var.win, var.img, 0,0);
    player_view(&var);
    circleBres(&var, var.j, var.i, 10);
    mlx_hook(var.win, 2, 0, key_manager, &var);
    mlx_loop(var.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:49:37 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/26 12:44:13 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>

#define DIMENSION 140
#define STD_I 500
#define STD_J 500
#define PI 3.14159265359
#define BUFFER_SIZE 10
#define SCALE 0.2
#define SPEED 50
#define A_W_H 70
#define W_WIDTH 1400
#define W_HIGHT 1000

typedef struct var
{
    double      i;
    double      j;
    double      pa;
	void	    *mlx;
	void	    *win;
    void        *img;
	char 	    *addr;
    char        **map;
    int         COLOR;
    int         size_x;
    int         size_y;
	int		    endian;
    int         key_A_D;
    int         key_W_S;
    int         key_R_L;
    int         key_U_D;
    int         line_img;
    int         bits_img;
    char        *addr_img;
    int         *img_text;
    int         endian_img;
	int		    line_length;
	int		    bits_per_pixel;
    char        hori_direction;
    char        vert_direction;
}	t_var;

void    ft_up(t_var *var);
int     ft_strlen(char *s);
void    ft_left(t_var *var);
void    ft_down(t_var *var);
void    save_map(t_var *var);
void    ft_right(t_var *var);
void    get_cords(t_var *var);
int     loop_event(t_var *var);
void    initiliaze(t_var *var);
char    *get_next_line(int fd);
int     key_manager(t_var *var);
size_t  ft_strchr(char *buffer);
void    draw_2d_map(t_var *var);
void	player_view(t_var *var);
void    ft_turn_left(t_var *var);
void    ft_turn_right(t_var *var);
int     key_up(int key, t_var *var);
int     key_down(int key, t_var *var);
double  degree_to_radian(int degree);
char    *ft_strdup(const char	*s1);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char	*s1, char	*s2);
char    *ft_substr(char *s, int start, int len);
void	cast_ray(double fov, t_var *var, int i);
void    circleBres(t_var *var, int xc, int yc, int r);
int     render_rect(t_var *var, int y, int x, int color);
void    drawCircle(t_var *var,int xc, int yc, int x, int y);
void	my_mlx_pixel_put(t_var *data, int x, int y, int color);
size_t  ft_strlcpy(char	*dst, const char	*src, size_t	len);
void    direction_option(double wall_x, double wall_y, t_var *var, double fov);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:49:37 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/07 11:37:11 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# define DIMENSION 1000
# define PI 3.14159265359
# define BUFFER_SIZE 10
# define SCALE 0.2
# define SPEED 0.2
# define A_W_H 70
# define W_WIDTH 12*140
# define W_HIGHT 13*140
# define SIGHT_SPEED 0.2

typedef struct var
{
	double		Xhitwall;
    double      Yhitwall;
    double      DeltaX;
    double      DeltaY;
    double      player_x;
    double      player_y;
    double      P_W_D;
    double      P_W_H;
    int         top_pixel;
    int         bottom_pixel;
    int         x_text;
    int         index;
    int         Fixed_point;
    int         y_text;
    int         pos;
    double      pa;
    char        *dst;
	void	    *mlx;
	void	    *win;
    void        *img;
	char 	    *addr;
    char        **map;
    int         size_x;
    int         size_y;
	int		    endian;
    int         key_A_D;
    int         key_W_S;
    int         key_R_L;
    int         key_U_D;
    int         line_img_N;
    int         line_img_S;
    int         line_img_E;
    int         line_img_W;
    char        *addr_img_N;
    char        *addr_img_S;
    char        *addr_img_E;
    char        *addr_img_W;
    int         *img_text_N;
    int         *img_text_S;
    int         *img_text_E;
    int         *img_text_W;
    int         bits_img;
    int         hieght_map;
    int         endian_img;
	int		    line_length;
	int		    bits_per_pixel;
    int         horizontal;
    int         vertical;
    char        direction;
}	t_var;


void calcul_indexes(t_var *var, int abs);
void x_wall_text(t_var *var, double fov, int line);
void paint_sky(t_var *var, int i);
void north_wall(t_var *var);
void south_wall(t_var *var);
void east_wall(t_var *var);
void west_wall(t_var *var);
void wall_pixels(t_var *var, double fov);
void paint_walls(t_var *var, int i, double fov);
void draw_3d(t_var *var, int abs, int i, double fov);
void horizontal_or_vertical(t_var *var, double wall_x, double wall_y, double fov);
void specify_derication(t_var *var, double wall_y, double wall_x);
void close_wall(t_var *var, double fov, int i);
void far_wall(t_var *var, double fov, int i);
double	normalize_angle(double angle);
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
void	player_view(t_var *var);
void    ft_turn_left(t_var *var);
void    ft_turn_right(t_var *var);
int     reset_keys(int key, t_var *var);
double  degree_to_radian(int degree);
char    *ft_strdup(const char	*s1);
int     initiliaze_keys(int key, t_var *var);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char	*s1, char	*s2);
char    *ft_substr(char *s, int start, int len);
void	ray_projection(double fov, t_var *var, int i);
void	my_mlx_pixel_put(t_var *data, int x, int y, int color);
size_t  ft_strlcpy(char	*dst, const char	*src, size_t	len);
void    direction_option(double wall_x, double wall_y, t_var *var, double fov);


#endif

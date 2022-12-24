/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:49:37 by mmanouze          #+#    #+#             */
/*   Updated: 2022/12/08 14:48:33 by mmanouze         ###   ########.fr       */
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

#define STD_I 500
#define STD_J 500
#define PI 3.14159265359
#define BUFFER_SIZE 10

typedef struct var
{
    char        **map;
	void	    *mlx;
	void	    *win;
    void        *img;
	char 	    *addr;
    int         h;
    int         w;
    int         size_x;
    int         size_y;
    int         i;
    int         j;
    int         tmp_i;
    int         tmp_j;
    double      pdx;
    double      pdy;
    double      pa;
	int		    bits_per_pixel;
	int		    line_length;
	int		    endian;
}	t_var;

char	*get_next_line(int fd);
int	ft_strlen(char *s);
size_t	ft_strchr(char *buffer);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char	*s1, char	*s2);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	len);
char	**ft_split(char const *s, char c);



#endif
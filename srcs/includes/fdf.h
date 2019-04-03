/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:12:24 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/03 14:17:45 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../includes/mlx_macro_keys.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define HEIGHT 800
# define WIDTH 1400
# define MENU_HEIGHT 692
# define MENU_WHIGHT 100
# define V_PAR 1
# define V_ISO 2
# define WHITE 0xFFFFFF
# define BLUE 0x1152CB

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef	struct		s_mlx
{
	void			*init;
	void			*win;
	int				clr;
	struct s_img	*img;

}					t_mlx;

typedef struct		s_coo
{
	int				x;
	int				y;
	int				z;
	struct s_coo	*next;
}					t_coo;

typedef struct		s_map
{
	int				x_max;
	int				y_max;
	int				z_min;
	int				z_max;
	int				view;
	int				ratio;
	int				x_rat;
	int				y_rat;
	float			zoom;
	float			z_rat;
	struct s_coo	*coo;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_all
{
	struct s_map	*map;
	struct s_mlx	*mlx;
}					t_all;

void				ft_free_coo(t_coo **map);
void				ft_free_map(t_map **map);
void				ft_free_glob(t_all **glob);
int					ft_init_coo(t_coo **list);
int					ft_init_map(t_map **map);
int					ft_init_glob(t_all **glob);
int					ft_add_coo(t_map **map, int x, int y, int z);
int					ft_read(char *str, t_map **map, int fd);
void				ft_free_tab(char **str);
int					ft_lstsize(t_coo **lst);
int					ft_init_t_mlx(t_mlx **mlx);
void				ft_free_t_mlx(t_mlx **mlx);
void				print_menu(t_mlx **mlx);
void				ft_print_map(t_map **map, t_mlx **mlx);
t_point				ft_add_t_p(int x, int y, int z, t_mlx *mlx);
int					ft_is_valid_str(char *str);
void				ctr(t_all *glob);
int					ft_lstlen_t_map(t_coo *coo);
int					ft_abs(int value);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
int					ft_init_t_mlx_2(t_mlx **mlx);
int					color(t_point cur, t_point a, t_point b, t_point d);
void				mouv(int key, t_map **map);
void				rat_z(int key, t_map **map);
void				view(int key, t_all **glob);
void				zoom(int key, t_map **map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:53:22 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/03 13:22:56 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point	ft_conv(t_map *map, t_point pnt)
{
	pnt.x *= map->ratio;
	pnt.y *= map->ratio;
	pnt.z *= map->ratio;
	pnt.x -= (map->x_max * map->ratio) / 2;
	pnt.y -= (map->y_max * map->ratio) / 2;
	if (map->view == V_PAR)
	{
		pnt.y = (pnt.y - (pnt.z * map->z_rat) * -sin(0.785398));
		pnt.x = (pnt.x - (pnt.z * map->z_rat) * cos(0.785398));
	}
	if (map->view == V_ISO)
	{
		pnt.x = (pnt.x - pnt.y) * cos(0.52);
		pnt.y = (-(pnt.z * map->z_rat) / map->ratio) + (pnt.x + pnt.y)
		* sin(0.52);
	}
	pnt.x += map->x_rat;
	pnt.y += map->y_rat;
	pnt.x += (WIDTH - MENU_WHIGHT) / 2;
	pnt.y += ((HEIGHT - MENU_HEIGHT) + map->y_max * map->ratio) / 2;
	pnt.x *= map->zoom;
	pnt.y *= map->zoom;
	return (pnt);
}

void			ft_put_line(t_point a, t_point b, t_mlx *mlx)
{
	t_point		delta;
	t_point		sign;
	t_point		cur;
	int			tab[2];

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	tab[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		ft_put_pixel(mlx, cur.x, cur.y, color(cur, a, b, delta));
		if ((tab[1] = tab[0] * 2) > -delta.y)
		{
			tab[0] -= delta.y;
			cur.x += sign.x;
		}
		if (tab[1] < delta.x)
		{
			tab[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

int				next_z(t_coo *lst, t_map *fdf)
{
	t_coo		*tmp;
	int			i;
	int			rlt;

	i = -1;
	tmp = lst;
	while (++i < fdf->x_max && tmp->next)
		tmp = tmp->next;
	rlt = tmp->z;
	return (rlt);
}

void			ft_put_line_h(t_map *m, t_mlx *mlx, int *x)
{
	t_coo		*coo_h;

	x[0] = -1;
	coo_h = m->coo;
	while (++x[0] < m->y_max)
	{
		x[1] = -1;
		while (++x[1] < m->x_max && m->coo->next)
		{
			if (x[1] != m->x_max - 1)
			{
				ft_put_line(ft_conv(m, ft_add_t_p(x[1], x[0], m->coo->z, mlx)),
				ft_conv(m, ft_add_t_p((x[1] + 1), x[0],
				m->coo->next->z, mlx)), mlx);
			}
			if (x[0] != m->y_max - 1)
			{
				ft_put_line(ft_conv(m, ft_add_t_p(x[1], x[0], m->coo->z, mlx)),
				ft_conv(m, ft_add_t_p(x[1], (x[0] + 1),
				next_z(m->coo, m), mlx)), mlx);
			}
			m->coo = m->coo->next;
		}
	}
	m->coo = coo_h;
}

void			ft_print_map(t_map **map, t_mlx **mlx)
{
	int		len;
	int		x[2];

	len = ft_lstlen_t_map((*map)->coo);
	(*map)->ratio = ((HEIGHT) / (*map)->x_max) < ((WIDTH) / (*map)->y_max)
		? (HEIGHT) / (*map)->x_max : (WIDTH) / (*map)->y_max;
	ft_put_line_h(*map, *mlx, x);
	mlx_put_image_to_window((*mlx)->init, (*mlx)->win, (*mlx)->img->ptr, 0, 0);
	print_menu(mlx);
}

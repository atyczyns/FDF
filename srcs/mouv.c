/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:54:57 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/01 10:34:08 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mouv(int key, t_map **map)
{
	if (key == KEY_LEFT)
		(*map)->x_rat += 30;
	if (key == KEY_RIGHT)
		(*map)->x_rat -= 30;
	if (key == KEY_DOWN)
		(*map)->y_rat -= 30;
	if (key == KEY_UP)
		(*map)->y_rat += 30;
}

void	rat_z(int key, t_map **map)
{
	if (key == KEY_PAD_SUB && (*map)->z_rat)
		(*map)->z_rat -= 0.1;
	if (key == KEY_PAD_ADD)
		(*map)->z_rat += 0.1;
}

void	view(int key, t_all **glob)
{
	if (key == KEY_C)
	{
		if ((*glob)->mlx->clr != 2)
			(*glob)->mlx->clr++;
		else
			(*glob)->mlx->clr = 0;
	}
	if (key == KEY_V || key == KEY_R)
	{
		if (key == KEY_V)
			(*glob)->map->view = ((*glob)->map->view == 1) ? 2 : 1;
		if (key == KEY_R)
			(*glob)->mlx->clr = 1;
		(*glob)->map->y_rat = 0;
		(*glob)->map->x_rat = 0;
		(*glob)->map->z_rat = 1;
		(*glob)->map->zoom = 1;
	}
}

void	zoom(int key, t_map **map)
{
	if ((*map)->zoom > 0 && key == KEY_PAGE_DOWN)
		(*map)->zoom -= 0.1;
	if (key == KEY_PAGE_UP)
		(*map)->zoom += 0.1;
}

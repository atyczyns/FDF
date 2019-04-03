/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:19:12 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/03 14:26:05 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		color_menu(void *win, void *ptr)
{
	int		x;
	int		y;

	y = 0;
	x = MENU_WHIGHT;
	while (x < WIDTH - MENU_WHIGHT)
	{
		y = MENU_HEIGHT;
		while (y < HEIGHT)
		{
			mlx_pixel_put(ptr, win, x, y, 0x1E1E1E);
			++y;
		}
		++x;
	}
}

void		print_menu(t_mlx **mlx)
{
	void	*win;
	void	*ptr;

	win = (*mlx)->win;
	ptr = (*mlx)->init;
	color_menu(win, ptr);
	mlx_string_put(ptr, win, 650, 660, 0x000000, "FdF");
	mlx_string_put(ptr, win, 200, 690, 0xFF0000, "How to use :");
	mlx_string_put(ptr, win, 200, 725, 0x00FF00, "ESC to quit");
	mlx_string_put(ptr, win, 600, 725, 0x00FF00, "PLUS and MINUS to zoom");
	mlx_string_put(ptr, win, 1000, 725, 0x00FF00, "R to reset");
	mlx_string_put(ptr, win, 200, 750, 0x00FFCA, "V to change view");
	mlx_string_put(ptr, win, 600, 750, 0x00DDCA,
	"PAGE: UP / DOWN to change z");
	mlx_string_put(ptr, win, 1000, 750, 0x00FFCA, "C to change color");
	mlx_string_put(ptr, win, 200, 775, 0x0038FF, "Arrow to mouve");
	mlx_string_put(ptr, win, 600, 775, 0x0038FF, "UP / DOWN / LEFT / RIGHT");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:43:53 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/01 10:51:46 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_lstlen_t_map(t_coo *coo)
{
	int		i;

	i = 0;
	while (coo->next)
	{
		coo = coo->next;
		i++;
	}
	return (i);
}

int		ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		i = (x * mlx->img->bpp / 8) + (y * mlx->img->size_l);
		mlx->img->data[i] = color;
		mlx->img->data[++i] = color >> 8;
		mlx->img->data[++i] = color >> 16;
	}
}

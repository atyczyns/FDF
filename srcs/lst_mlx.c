/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:55:22 by becaraya          #+#    #+#             */
/*   Updated: 2019/03/29 16:10:37 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_init_t_mlx_2(t_mlx **mlx)
{
	if (!((*mlx)->img->ptr = mlx_new_image((*mlx)->init, WIDTH, HEIGHT)))
	{
		mlx_destroy_window((*mlx)->init, (*mlx)->win);
		free((*mlx)->img);
		free((*mlx)->init);
		free(mlx);
		return (EXIT_FAILURE);
	}
	if (((*mlx)->img->data = mlx_get_data_addr((*mlx)->img->ptr,
			&((*mlx)->img->bpp), &((*mlx)->img->size_l),
				&((*mlx)->img->endian))) == NULL)
	{
		free((*mlx)->img->ptr);
		mlx_destroy_window((*mlx)->init, (*mlx)->win);
		free((*mlx)->img);
		free((*mlx)->init);
		free(mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			ft_init_t_mlx(t_mlx **mlx)
{
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		return (EXIT_FAILURE);
	if (!((*mlx)->init = mlx_init()))
	{
		free(mlx);
		return (EXIT_FAILURE);
	}
	if (!((*mlx)->win = mlx_new_window((*mlx)->init, WIDTH, HEIGHT, "FdF"))
		|| !((*mlx)->img = (t_img *)malloc(sizeof(t_img))))
	{
		if ((*mlx)->win)
			mlx_destroy_window((*mlx)->init, (*mlx)->win);
		free((*mlx)->init);
		free(mlx);
		return (EXIT_FAILURE);
	}
	if (ft_init_t_mlx_2(mlx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	(*mlx)->clr = 1;
	return (EXIT_SUCCESS);
}

void		ft_free_t_mlx(t_mlx **mlx)
{
	if ((*mlx))
	{
		mlx_destroy_image((*mlx)->init, (*mlx)->img->ptr);
		free((*mlx)->img);
		mlx_destroy_window((*mlx)->init, (*mlx)->win);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:59:53 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/01 13:15:04 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_free_map(t_map **map)
{
	if ((*map)->coo)
		ft_free_coo(&(*map)->coo);
	if (*map)
		free(*map);
}

void		ft_free_coo(t_coo **coo)
{
	if (((*coo)->next))
		ft_free_coo(&(*coo)->next);
	if (*coo)
		free(*coo);
}

void		ft_free_glob(t_all **glob)
{
	if ((*glob)->map)
		ft_free_map(&(*glob)->map);
	if ((*glob)->mlx)
		ft_free_t_mlx(&(*glob)->mlx);
	free(*glob);
}

t_point		ft_add_t_p(int x, int y, int z, t_mlx *mlx)
{
	t_point		new;

	new.x = x;
	new.y = y;
	new.z = z;
	if (mlx->clr == 0)
	{
		new.color = 256 * 256 * (int)(127.5 * (cos(z) + 1)) + 256
		* (int)(127.5 * (sin(z) + 1)) + (int)(127.5 * (1 - cos(z)));
	}
	else if (mlx->clr == 1)
		new.color = WHITE;
	else
		new.color = BLUE;
	return (new);
}

int			ft_add_coo(t_map **map, int x, int y, int z)
{
	t_coo	*new;

	if ((*map)->coo->x == -1 && (*map)->coo->y == -1 && (*map)->coo->z == -1)
	{
		(*map)->coo->x = x;
		(*map)->coo->y = y;
		(*map)->coo->z = z;
		(*map)->z_max = z;
		(*map)->z_min = z;
	}
	else
	{
		if (!(new = (t_coo *)malloc(sizeof(t_coo))))
			return (EXIT_FAILURE);
		new->next = NULL;
		new->x = x;
		new->y = y;
		new->z = z;
		(z < (*map)->z_min) ? (*map)->z_min = z : 0;
		(z > (*map)->z_max) ? (*map)->z_max = z : 0;
		(*map)->coo->next = new;
		(*map)->coo = new;
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:23:52 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/01 13:33:42 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_init_glob(t_all **glob)
{
	if (!((*glob) = (t_all *)malloc(sizeof(t_all))))
		return (EXIT_FAILURE);
	if (ft_init_map(&(*glob)->map) == EXIT_FAILURE)
	{
		free(glob);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			ft_init_map(t_map **map)
{
	if (!((*map) = (t_map *)malloc(sizeof(t_map))))
		return (EXIT_FAILURE);
	if (ft_init_coo(&(*map)->coo) == EXIT_FAILURE)
	{
		ft_free_map(map);
		return (EXIT_FAILURE);
	}
	(*map)->view = V_PAR;
	(*map)->x_rat = 0;
	(*map)->y_rat = 0;
	(*map)->z_rat = 1;
	(*map)->zoom = 1;
	return (EXIT_SUCCESS);
}

int			ft_init_coo(t_coo **coo)
{
	if (!((*coo) = (t_coo *)malloc(sizeof(t_coo))))
		return (EXIT_FAILURE);
	(*coo)->x = -1;
	(*coo)->y = -1;
	(*coo)->z = -1;
	(*coo)->next = NULL;
	return (EXIT_SUCCESS);
}

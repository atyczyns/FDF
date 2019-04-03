/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:12:16 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/03 13:23:55 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_all	*glob;
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf [map]");
		return (0);
	}
	if (ft_init_glob(&glob) == EXIT_FAILURE)
		return (0);
	if (ft_read(argv[1], &glob->map, fd) == EXIT_FAILURE
			|| (ft_init_t_mlx(&glob->mlx) == EXIT_FAILURE))
	{
		ft_putendl("Map Error");
		ft_free_glob(&glob);
		return (0);
	}
	ft_print_map(&glob->map, &(*glob).mlx);
	ctr(glob);
	mlx_loop(glob->mlx->init);
	return (0);
}

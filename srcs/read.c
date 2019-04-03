/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 10:06:43 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/03 13:23:30 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_add_l(char **str, t_map **map, int *x, int y)
{
	int		i;
	char	**tmp;

	i = 0;
	if ((tmp = ft_strsplit(*str, ' ')) == NULL)
		return (EXIT_FAILURE);
	while (tmp[i])
	{
		if (ft_is_valid_str(tmp[i]) == 0
			|| ft_add_coo((map), i, y, ft_atoi(tmp[i])) == EXIT_FAILURE)
		{
			ft_free_tab(tmp);
			free(tmp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (*x == 0)
		*x = i;
	else if (*x != i)
		i = 0;
	ft_free_tab(tmp);
	free(tmp);
	return ((i == 0) ? EXIT_FAILURE : EXIT_SUCCESS);
}

static int	do_gnl(int fd, t_map **map, char *str, int error)
{
	int		y;
	char	*line;

	y = 0;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while ((error = get_next_line(fd, &line)) > 0)
	{
		if (ft_add_l(&line, map, &(*map)->x_max, y++) == EXIT_FAILURE)
		{
			ft_strdel(&line);
			close(fd);
			return (-1);
		}
		ft_strdel(&line);
	}
	close(fd);
	return (y);
}

int			ft_read(char *str, t_map **map, int fd)
{
	int		y;
	int		error;
	t_coo	*map_h;

	error = 0;
	map_h = (*map)->coo;
	(*map)->x_max = 0;
	y = do_gnl(fd, map, str, error);
	(*map)->coo = map_h;
	if (error == -1 || y < 1 || (y == 1 && (*map)->x_max == 1))
		return (EXIT_FAILURE);
	if (((*map)->y_max = y) != 0)
	{
		(*map)->coo = map_h;
		while ((*map)->coo)
			(*map)->coo = (*map)->coo->next;
		(*map)->coo = map_h;
	}
	else
		(*map)->coo = NULL;
	return (((*map)->y_max > 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

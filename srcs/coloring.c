/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:55:27 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/01 10:45:07 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double prct)
{
	return ((int)((1 - prct) * start + prct * end));
}

int				color(t_point cur, t_point a, t_point b, t_point d)
{
	int		green;
	int		blue;
	int		red;
	double	prct;

	if (a.color == b.color)
		return (a.color);
	if (d.x > d.y)
		prct = percent(a.x, b.x, cur.x);
	else
		prct = percent(a.y, b.y, cur.y);
	red = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, prct);
	green = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, prct);
	blue = get_light(a.color & 0xFF, b.color & 0xFF, prct);
	return ((red << 16) | (green << 8) | blue);
}

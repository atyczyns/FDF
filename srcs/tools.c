/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:25:56 by becaraya          #+#    #+#             */
/*   Updated: 2019/03/21 16:30:59 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_lstsize(t_coo **lst)
{
	int		i;

	i = 0;
	while ((*lst)->next)
	{
		(*lst) = (*lst)->next;
		i++;
	}
	return (i);
}

void		ft_free_tab(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(*str);
	str = NULL;
}

int			ft_is_valid_str(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

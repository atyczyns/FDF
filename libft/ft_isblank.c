/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:55:25 by becaraya          #+#    #+#             */
/*   Updated: 2018/11/17 15:58:13 by becaraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isblank(int c)
{
	if (c == 32 || c == 9)
		return (1);
	return (0);
}
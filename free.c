/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:33:00 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/04 14:05:15 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(mlx_game *var)
{
	int	i;

	if (var->map && *var->map)
	{
		i = 0;
		while (var->map[i])
		{
			free(var->map[i]);
			i++;
		}
		free(var->map);
	}
}

void	free_map_cpy(mlx_game *var)
{
	int	i;

	if (var->map_cpy && *var->map_cpy)
	{
		i = 0;
		while (var->map_cpy[i])
		{
			free(var->map_cpy[i]);
			i++;
		}
		free(var->map_cpy);
	}
}

void	multy_free(mlx_game *var)
{
	free_map(var);
	free_map_cpy(var);
}
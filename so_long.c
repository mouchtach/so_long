/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/04/05 16:27:00 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *argv, mlx_game *var)
{
	int	map;

	if (!check_name(argv))
	{
		printf("name error\n");
		exit(1);
	}
	map = open(argv, O_RDONLY, 0777);
	if (map == -1)
	{
		printf("file not exist \n");
		exit(1);
	}
	var->count = count_lines(map);
	close(map);
	map = open(argv, O_RDONLY, 0777);
	return (map);
}

int	main(int argc, char **argv)
{
	mlx_game var;
	int fd_map;

	if (argc == 2)
	{
		fd_map = open_file(argv[1], &var);
		var.map = read_map(fd_map, &var);
		if (!check_map(&var))
			return (free_map(&var), 1);
		so_long(&var);
	}
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:01:06 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/22 05:53:03 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    int map;
    int count;
    char **map_array;

    if (argc != 2)
        return (0);
    check_name(argv[1]);
    map = open(argv[1], O_RDONLY, 0777);
    if (!map)
        printf("file not exist \n");
    count = count_lines(map);
    close (map);
    map = open("map.ber", O_RDONLY, 0777);
    map_array = read_map(map, count);
    parsing_arry(map_array, count);

}
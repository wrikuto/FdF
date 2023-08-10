/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:55:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/10 14:56:08 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static t_fdf	*init_fdf(const char *arg)
// {
// 	t_fdf	*data;
// 	char	*title;

// 	title = ft_strjoin("FdF - ", arg);
// 	data = malloc(sizeof(t_fdf));
// 	if (data == NULL)
// 		display_error_and_exit("malloc error\n");
// 	data->mlx = mlx_init();
// 	if (data->mlx == NULL)
// 		display_error_and_exit("failed mlx_init.\n");
// 	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
// 	if (data->win == NULL)
// 		display_error_and_exit("failed initializing window.\n");
// 	free (title);
// 	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
// 	if (data->img == NULL)
// 		display_error_and_exit("failed initializing image.\n");
// 	// data->map = NULL;
// 	// data->cam = NULL;
	
// 	return (data);
// }

int main(int argc, char **argv)
{
	// t_fdf	*data;

	if (argc == 2)
	{
		printf("argv: %s\n", argv[1]);
		// data = init_fdf(*argv[1]);

		// data->map = init_map();
		chk_arg(argv[1]);
		chk_file_data(argv[1]);
	}
	else
		error_and_exit("invalid arg\n");
	printf("\n\n");
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}

// static t_map	*init_map(void)
// {
// 	t_map	*map;

// 	map = malloc(sizeof(t_map));
// 	if (map == NULL)
// 		display_error_and_exit("failed initializing map");
// 	map->height = 0;
// 	map->width = 0;
// 	map->array = NULL;
// 	map->z_max = 0;
// 	map->z_min = 0;
// 	return (map);
// }

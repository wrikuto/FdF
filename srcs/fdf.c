/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:55:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/12 13:58:43 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_fdf	*init_fdf(const char *arg)
{
	t_fdf	*env;
	char	*title;

	title = ft_strjoin("FdF - ", arg);
	env = malloc(sizeof(t_fdf));
	if (env == NULL)
		error_and_exit("malloc error\n");
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		error_and_exit("failed mlx_init.\n");
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (env->win == NULL)
		error_and_exit("failed initializing window.\n");
	free (title);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (env->img == NULL)
		error_and_exit("failed initializing image.\n");
	env->addr = mlx_get_data_addr(env->img, &env->bpp, \
			&env->size_line, &env->endian);
	env->map = NULL;
	// data->cam = NULL;
	return (env);
}

static	t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_and_exit("failed initializing map.\n");
	map->height = 0;
	map->width = 0;
	map->point3D = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

// ---------------------------------------------------------------------------

int	main(int argc, char **argv)
{
	printf("\n~~~~~~~~~~~~~~~| FdF_test |~~~~~~~~~~~~~~~~\n\n");
	t_fdf	*env;

	if (argc == 2)
	{
		env = init_fdf(argv[1]);
		env->map = init_map();
		chk_arg(argv[1]);
		chk_valid(argv[1]);
		// get_mapdata(argv[1], env->map);
		printf("height: %d\n", get_height(argv[1]));
		printf("width : %d\n", get_width(argv[1]));


	exit (0);
	}
	else
		error_and_exit("invalid arg\n");
	// printf("\n\n");
	return (0);
}

// ---------------------------------------------------------------------------

__attribute__((destructor))
static void destructor()
{
	printf("\n\n~~~~~~~~~~~~~| CHEKING_LEAKS |~~~~~~~~~~~~~\n\n");
    system("leaks -q fdf");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t| finish |\n\n");
}

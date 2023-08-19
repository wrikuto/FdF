/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:55:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/19 23:36:17 by wrikuto          ###   ########.fr       */
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
	env->addr = mlx_get_data_addr(env->img, &(env->bpp), \
			&(env->size_line), &(env->endian));
	env->map = NULL;
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
	map->max_ix = DBL_MIN;
	map->min_ix = DBL_MAX;
	map->max_iy = DBL_MIN;
	map->min_iy = DBL_MAX;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

// int	main(int argc, char **argv)
// {
// 	t_fdf	*env;

// 	if (argc == 2)
// 	{
// 		chk_arg(argv[1]);
// 		chk_valid(argv[1]);
// 		env = init_fdf(argv[1]);
// 		env->map = init_map();
// 		get_mapdata(argv[1], env->map);
// 		trans_data(env->map);
// 		mlx_key_hook(env->win, close_esc, env);
// 		mlx_hook(env->win, 17, 0, close_win, env);
// 		draw_line(env);
// 		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
// 		mlx_loop(env->mlx);
// 	}
// 	else
// 		error_and_exit("invalid arg\n");
// 	return (0);
// }

// __attribute__((destructor))
// static void	destructor()
// {
// 	printf("\n\n~~~~~~~~~~~~~| CHEKING_LEAKS |~~~~~~~~~~~~~\n\n");
//     system("leaks -q fdf");
// 	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t| finish |\n\n");
// }

int	main(int argc, char **argv)
{
	printf("\n~~~~~~~~~~~~~~~| FdF_test |~~~~~~~~~~~~~~~~\n\n");
	t_fdf	*env;
	t_point	*point3D;

	if (argc == 2)
	{
		chk_arg(argv[1]);
		chk_valid(argv[1]);
		env = init_fdf(argv[1]);
		env->map = init_map();
		get_mapdata(argv[1], env->map);
		point3D = env->map->point3D;
		printf("grid:\n");
		for (size_t i = 0; i < (env->map->height * env->map->width); i++)
			printf("count: %zu, X: %f, Y: %f, Z: %f, COL: %d\n", i, point3D[i].x, point3D[i].y, point3D[i].z, point3D[i].color);
		trans_data(env->map);
		printf("\niso:\n");
		for (size_t j = 0; j < (env->map->height * env->map->width); j++)
			printf("count: %zu, X: %f, Y: %f\n", j, point3D[j].iso_x, point3D[j].iso_y);
		printf("\n");
		printf("\nscreen:\n");
		for (size_t k = 0; k < (env->map->height * env->map->width); k++)
			printf("count: %zu, X: %f, Y: %f\n", k, point3D[k].screen_x, point3D[k].screen_y);
		// draw_to_screen(env);
		mlx_key_hook(env->win, close_esc, env);
		mlx_hook(env->win, 17, 0, close_win, env);
		draw_line(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_loop(env->mlx);
	}
	else
		error_and_exit("invalid arg\n");
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	printf("\n\n~~~~~~~~~~~~~| CHEKING_LEAKS |~~~~~~~~~~~~~\n\n");
    system("leaks -q fdf");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t| finish |\n\n");
}
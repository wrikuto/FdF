/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:55:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/05 16:44:12 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static t_fdf	*init_fdf(const char *arg)
{
	t_fdf	*data;
	char	*title;

	title = ft_strjoin("FdF - ", arg);
	data = malloc(sizeof(t_fdf));
	if (data == NULL)
		display_error_and_exit("malloc error\n");
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		display_error_and_exit("failed mlx_init.\n");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	if (data->win == NULL)
		display_error_and_exit("failed initalizing window");
	free (title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->height = 0;
	data->width = 0;
	data->scale = 0;
	data->iso = 1;
	
	
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argv == 2)
	{
		fdf = init_fdf(*argv[1]);
	}
	else
		display_error_and_exit("invalid arg\n");
}
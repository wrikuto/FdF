/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:57:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/04 17:01:30 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include <stdlib.h>

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init(); // MiniLibXの初期化
    win = mlx_new_window(mlx, 800, 600, "MiniLibX Window"); // ウィンドウの作成

    // グラフィックスの描画
    int x1 = 100;
    int y1 = 100;
    int x2 = 700;
    int y2 = 500;

    mlx_pixel_put(mlx, win, x1, y1, 0xFF0000); // 始点を赤色で描画

    // Bresenhamアルゴリズムで線を描画
    int dx;
    int dy;
    int increment_x;
    int increment_y;

    dx = x2 - x1;
    dy = y2 - y1;
	if (dx > 0)
		increment_x = 1;
	else
		increment_x = -1;
	if (dy > 0)
		increment_y = 1;
	else
		increment_y = -1;
    dx = abs(dx);
    dy = abs(dy);
    int two_dy = 2 * dy;
    int two_dy_minus_dx = 2 * dy - dx;
    int y = y1;

	int x = x1 + increment_x;
	while (x != x2)
	{
		mlx_pixel_put(mlx, win, x, y, 0xFF0000); // 線分を赤色で描画

		if (two_dy_minus_dx > 0)
		{
			y += increment_y;
			two_dy_minus_dx -= 2 * dx;
		}
		two_dy_minus_dx += two_dy;

		x += increment_x;
	}

    mlx_pixel_put(mlx, win, x2, y2, 0xFF0000); // 終点を赤色で描画

    mlx_loop(mlx); // イベントループ開始

    return 0;
}

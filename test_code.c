#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t color = 0x000000;  // 初期化
	uint32_t color2 = 0x00002A;	// 最初の色

	// 加える色
	uint32_t newred = 1;
	uint32_t newgreen = 1;
	uint32_t newblue = 1;

	// 加算
	color += ((color2) & 0xFF0000) + (newred<<16);
	color += (color2 & 0x00FF00) + (newgreen<<8);
	color += (color2 & 0x0000FF) + (newblue);

    printf("Color: 0x%08X\n", color);
	// printf("TEST,%d \n", (color2));
	// printf("dif: %d \n", ((color >> 16) & 0xFF) - ((color2 >> 16) & 0xFF));
    // printf("Red Component: %d\n", redComponent);
    // printf("Green Component: %d\n", greenComponent);
    // printf("Blue Component: %d\n", blueComponent);

    return 0;
}

// int main() {
//     uint32_t color = 0x000000;  // 初期化
//     uint32_t color2 = 0x111111; // 最初の色

//     // 加える色
//     uint32_t newred = 1;
//     uint32_t newgreen = 1;
//     uint32_t newblue = 1;

//     // 赤成分の加算
//     color += ((color2 >> 16) & 0xFF) + newred;

//     // 緑成分の加算
//     color += ((color2 >> 8) & 0xFF) + newgreen;

//     // 青成分の加算
//     color += (color2 & 0xFF) + newblue;

//     printf("Original Color: 0x%08X\n", color2);
//     printf("Modified Color: 0x%08X\n", color);

//     return 0;
// }
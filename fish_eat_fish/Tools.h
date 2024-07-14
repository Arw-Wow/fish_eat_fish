#pragma once

#include <graphics.h>

#pragma comment(lib, "Msimg32.lib")

// 翻转第一个参数图片并保存到第二个参数图片
void flip_image(IMAGE* src, IMAGE* dst);

void putimage_alpha(int x, int y, IMAGE* img);

// void putimage_alpha(const Camera& camera, int x, int y, IMAGE* img);

void putimage_alpha(int dst_x, int dst_y, int width, int height, IMAGE* img, int src_x, int src_y);

// void line_alpha(const Camera& camera, int x1, int y1, int x2, int y2);

void white_image(IMAGE* src, IMAGE* dst);

inline constexpr int to_vkcode(char c)
{
	return (0x41 + c - 'a');
}

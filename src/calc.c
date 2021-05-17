/*
** EPITECH PROJECT, 2021
** calc
** File description:
** world
*/

#include "world.h"

float float_radians(float angle)
{
    float temp = (angle * (M_PI / 180.0));
    return (temp);
}

float calc(int posx, int posy, float mapx, float mapy)
{
    float tmp = ((posx * posx - 2 * posx * mapx + mapx * mapx) + (posy * posy - 2 * posy * mapy + mapy * mapy));
    return (tmp);
}

float calcx(int x, int y, float r, int i, int j, map_t p)
{
    float tempx = (i + cosf(r) * (x - i) - sinf(r) * (y - j)) * p.zoom;
    return (tempx);
}

float calcy(int x, int y, float r, int i, int j, map_t p)
{
    float tempy = (j + sinf(r) * (x - i) + cosf(r) * (y - j)) * p.zoom;
    return (tempy);
}

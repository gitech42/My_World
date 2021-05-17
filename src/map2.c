/*
** EPITECH PROJECT, 2021
** world
** File description:
** mapp
*/

#include "world.h"

void create_maplines(map_t p)
{
    int x = 0;
    int y = 0;
    sfVertexArray *vertex_array = sfVertexArray_create();

    while (y < MAP_Y) {
        for (x = 0; x < MAP_X - 1; x++)
            create_2(vertex_array, p.map[y][x], p.map[y][x + 1]);
        y++;
    }
    while (x < MAP_X) {
        for (y = 0; y < MAP_Y - 1; y++)
            create_2(vertex_array, p.map[y][x], p.map[y + 1][x]);
        x++;
    }
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    sfRenderWindow_drawVertexArray(p.window, vertex_array, NULL);
}

void map(map_t p)
{
    my_2d_map(p);
    create(p);
    create_maplines(p);
}

sfVector2f project_iso_point(int x, int y, int z, map_t p)
{
    sfVector2f point = {0, 0};
    sfVector2f angle = {float_radians(p.pos.x), float_radians(p.pos.y)};

    point.x = cosf(angle.x) * x - cosf(angle.x) * y + p.view_x;
    point.y = sinf(angle.y) * y + sinf(angle.y) * x - z + p.view_y;
    return (point);
}

float **malloc_tab(map_t p)
{
    p.tab = malloc(sizeof(float *) * MAP_Y);

    for (int y = 0; y < MAP_Y; y++) {
        p.tab[y] = malloc(sizeof(float) * MAP_X);
        for (int x = 0; x < MAP_X; x++)
            p.tab[y][x] = 0;
    }
    return (p.tab);
}

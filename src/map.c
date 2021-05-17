/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** map
*/

#include "world.h"

void create(map_t p)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    for (int y = 0; y < MAP_Y - 1; y++) {
        for (int x = 0; x < MAP_X - 1; x++) {
            sfVertex vertex1 = {.position = p.map[y][x], .color = sfBlack};
            sfVertex vertex2 = {.position = p.map[y][x + 1], .color = sfBlack};
            sfVertex vertex3 = {.position = p.map[y + 1][x + 1], .color = sfBlack};
            sfVertex vertex4 = {.position = p.map[y + 1][x], .color = sfWhite};
            sfVertexArray_append(vertex_array, vertex1);
            sfVertexArray_append(vertex_array, vertex2);
            sfVertexArray_append(vertex_array, vertex3);
            sfVertexArray_append(vertex_array, vertex4);
        }
    }
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(p.window, vertex_array, NULL);
}

sfVector2f **create_2d_map(map_t p)
{
    float x1 = 0;
    float y1 = 0;
    float z1 = 0;
    sfVector2f **copy_map = malloc(sizeof(sfVector2f *) * (MAP_Y + 1));

    copy_map[MAP_Y] = NULL;
    for (int y = 0; y < MAP_Y; y++) {
        copy_map[y] = malloc(sizeof(sfVector2f) * (MAP_X));
    }
    return (copy_map);
}

void my_2d_map(map_t p)
{
    float x1 = 0;
    float y1 = 0;

    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++) {
            x1 = calcx(x, y, float_radians(p.rotation), MAP_X / 2, MAP_Y / 2, p);
            y1 = calcy(x, y, float_radians(p.rotation), MAP_X / 2, MAP_Y / 2, p);
            p.map[y][x] = project_iso_point(x1, y1, p.tab[y][x] * p.zoom, p);
        }
    }
}

void create_2(sfVertexArray *vertex_array, sfVector2f point1, sfVector2f point2)
{
    sfVertex vertex1 = {.position = point1, .color = sfBlue};
    sfVertex vertex2 = {.position = point2, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
}

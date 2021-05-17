/*
** EPITECH PROJECT, 2021
** world
** File description:
** mouse
*/

#include "world.h"

void mouse_altitude(map_t p)
{
    float tmp = 2000;
    sfVector2i vect = (sfVector2i){0, 0};
    sfVector2i mpos = sfMouse_getPositionRenderWindow(p.window);
    float cal = 0;

    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x <= MAP_X; x++) {
            cal = calc(mpos.x, mpos.y, p.map[y][x].x, p.map[y][x].y);
            if (cal < tmp) {
                vect = (sfVector2i){x, y};
                tmp = cal;
            }
        }
    }
    p.posmouse = vect;
    if (p.event.mouseButton.button == sfMouseLeft)
        p.tab[p.posmouse.y][p.posmouse.x] += 4.0 / p.zoom;
    if (p.event.mouseButton.button == sfMouseRight)
        p.tab[p.posmouse.y][p.posmouse.x] -= 4.0 / p.zoom;

}

void save_file(map_t p)
{
    char *file = "map.legend";
    int fd = open(file, O_CREAT | O_WRONLY, 0666);

    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++) {
            my_put_nbr_fd(fd, p.tab[y][x]);
            write(fd, " ", 1);
        }
        write(fd, "\n", 1);
    }
    close(fd);
}

void check_tool(map_t p)
{
    sfFloatRect rec3 = sfSprite_getGlobalBounds(p.alt);
    sfFloatRect rec2 = sfSprite_getGlobalBounds(p.load);
    sfFloatRect rec = sfSprite_getGlobalBounds(p.save);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(p.window);

    if (sfFloatRect_contains(&rec, mouse.x, mouse.y) == sfTrue)
        save_file(p);
    if (sfFloatRect_contains(&rec2, mouse.x, mouse.y) == sfTrue)
        for (int y = 0; y < MAP_Y; y++)
            for (int x = 0; x < MAP_X; x++)
                p.tab[y][x] = 0;
    if (sfFloatRect_contains(&rec3, mouse.x, mouse.y) == sfTrue)
        for (int y = 0; y < MAP_Y; y++)
            for (int x = 0; x < MAP_X; x++)
                p.tab[y][x] = ((rand() % 20) / p.zoom);
}

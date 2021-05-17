/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** m
*/

#include "world.h"

int main(int ac, char **av)
{
    map_t p;
     int x = 0;
     int y = 0;

    p = init_struct(p);
    sfRenderWindow_setFramerateLimit(p.window, 60);
    while (sfRenderWindow_isOpen(p.window)) {
        sfRenderWindow_clear(p.window, sfBlack);
        while (sfRenderWindow_pollEvent(p.window, &p.event)) {
            if(p.event.type == sfEvtClosed)
                sfRenderWindow_close(p.window);
            if (p.event.type == sfEvtKeyPressed) {
                if (p.event.key.code == sfKeyT)
                    p.zoom += 0.8;
                if (p.event.key.code == sfKeyG)
                    p.zoom -= 0.8;
                if (p.event.key.code == sfKeyLeft)
                    p.rotation -= 4.5;

                if (p.event.key.code == sfKeyRight)
                    p.rotation += 4.5;
                if (p.event.key.code == sfKeyUp) {
                    p.view_y += 4.5;
                    p.pos.y -= 0.03;
                }
                if (p.event.key.code == sfKeyDown) {
                    p.view_y -= 4.5;
                    p.pos.y += 1.2;
                }
                if (p.event.key.code == sfKeyZ)
                    p.view_y -= 12;
                  if (p.event.key.code == sfKeyS)
                      p.view_y += 12;
                  if (p.event.key.code == sfKeyQ)
                      p.view_x -= 12;
                  if (p.event.key.code == sfKeyD)
                      p.view_x += 12;
            }
            if (p.event.type == sfEvtMouseButtonPressed) {
                mouse_altitude(p);
                check_tool(p);
            }
        }
        map(p);
        display_sprite(p);
        sfRenderWindow_display(p.window);
    }
}

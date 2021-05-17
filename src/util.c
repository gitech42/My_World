/*
** EPITECH PROJECT, 2021
** world
** File description:
** util
*/

#include "world.h"

void display_sprite(map_t p)
{
    sfRenderWindow_drawSprite(p.window, p.alt, NULL);
    sfRenderWindow_drawSprite(p.window, p.save, NULL);
    sfRenderWindow_drawSprite(p.window, p.load, NULL);
}

int my_write(int fd, char c)
{
    write(fd, &c, 1);
    return (4);
}

int my_put_nbr_fd(int fd, int nbr)
{
    if (nbr < 0) {
        write(fd, "-", 1);
        my_put_nbr_fd(fd, -nbr);
    }
    else if (nbr >= 10) {
        my_put_nbr_fd(fd, nbr / 10);
        my_write(fd, nbr % 10 + '0');
    }
    else if (nbr < 10)
        my_write(fd, nbr + '0');
}

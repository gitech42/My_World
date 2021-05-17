/*
** EPITECH PROJECT, 2021
** world
** File description:
** init
*/

#include "world.h"

map_t init_struct(map_t p)
{
    sfVideoMode md = {1920, 1080, 32};

    p.alt_scale.x = 0.25;
    p.alt_scale.y = 0.25;
    p.pos_alt.y = 250;
    p.pos_save.x = 20;
    p.pos_load.y = 120;
    p.loadscale.x = 0.25;
    p.loadscale.y = 0.25;
    p.savescale.x = 3;
    p.savescale.y = 3;
    p.load = sfSprite_create();
    p.alt = sfSprite_create();
    p.talt = sfTexture_createFromFile("image/batterie.png", NULL);
    p.tload = sfTexture_createFromFile("image/load.png", NULL);
    p.save = sfSprite_create();
    p.tsave = sfTexture_createFromFile("image/diskette.png", NULL);
    sfSprite_setTexture(p.save, p.tsave, sfTrue);
    sfSprite_setTexture(p.alt, p.talt, sfTrue);
    sfSprite_setTexture(p.load, p.tload, sfTrue);
    sfSprite_setScale(p.load, p.loadscale);
    sfSprite_setScale(p.save, p.savescale);
    sfSprite_setScale(p.alt, p.alt_scale);
    sfSprite_setPosition(p.load, p.pos_load);
    sfSprite_setPosition(p.alt, p.pos_alt);
    sfSprite_setPosition(p.save, p.pos_save);
    p.posmouse = (sfVector2i){0, 0};
    p.rotation = 0;
    p.zoom = 11.2f;
    p.tab = malloc_tab(p);
    p.view_x = 760;
    p.view_y = 360 - (p.zoom * MAP_Y / 2 * sqrt(2));
    p.pos = (sfVector2i) {40, 55};
    p.map = create_2d_map(p);
    p.window = sfRenderWindow_create(md, "MyWorld", sfClose | sfResize, NULL);
    return (p);
}

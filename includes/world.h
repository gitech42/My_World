/*
** EPITECH PROJECT, 2021
** my world
** File description:
** world
*/

#define MAP_X  70
#define MAP_Y  45
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>
#include <SFML/System.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>

typedef struct map_s
{
    sfVector2f alt_scale;
    sfVector2f pos_load;
    sfVector2f pos_save;
    sfVector2f loadscale;
    sfVector2f savescale;
    sfVector2f pos_alt;
    sfSprite *alt;
    sfTexture *talt;
    sfSprite *load;
    sfTexture *tload;
    sfSprite *save;
    sfTexture *tsave;
    float zoom;
    float **tab;
    int view_x;
    sfVector2f **map;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i pos;
    int view_y;
    float rotation;
    sfVector2i posmouse;
    
} map_t;

float float_radians(float angle);
float calc(int posx, int posy, float mapx, float mapy);
map_t init_struct(map_t p);
void create_maplines(map_t p);
void map(map_t p);
sfVector2f project_iso_point(int x, int y, int z, map_t p);
float **malloc_tab(map_t p);
void create(map_t p);
sfVector2f **create_2d_map(map_t p);
void my_2d_map(map_t p);
void create_2(sfVertexArray *vertex_array, sfVector2f point1, sfVector2f point2);
void mouse_altitude(map_t p);
void save_file(map_t p);
void check_tool(map_t p);
void display_sprite(map_t p);
int my_write(int fd, char c);
int my_put_nbr_fd(int fd, int nbr);
float calcx(int x, int y, float r, int i, int j, map_t p);
float calcy(int x, int y, float r, int i, int j, map_t p);

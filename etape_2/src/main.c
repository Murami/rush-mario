/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Sat Mar  8 16:40:07 2014 SADOWSKI Geoffroy
*/

#include "epikong.h"

SDL_Surface*	epikong_init(char* filename, t_map* map, t_objlist* objlist)
{
  memset(objlist, 0, sizeof(t_objlist));
  load_map(filename, map);
  load_gameobject(map, objlist);
  load_sprites();
  SDL_Init(SDL_INIT_VIDEO);
  return (xSDL_SetVideoMode(map->width * CASE_SIZE,
			    map->height * CASE_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF));
}

int	manage_game(t_map* map, t_objlist* objlist)
{
  int	still;

  still = manage_event(map, objlist);
  manage_physics(map, objlist);
  manage_ia(map, objlist);
  return (still);
}

void	draw_game(t_map* map, t_objlist* objlist, SDL_Surface* screen)
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  draw_map(map, screen);
  draw_gameobject(objlist, screen);
  SDL_Flip(screen);
}

void	epikong(char* filename)
{
  t_map		map;
  t_objlist	objlist;
  SDL_Surface*	screen;
  int		still;

  screen = epikong_init(filename, &map, &objlist);
  still = 1;
  while (still)
    {
      still = manage_game(&map, &objlist);
      draw_game(&map, &objlist, screen);
    }
}

int	main(int ac, char** av)
{
  if (ac >= 2)
    epikong(av[1]);
  return (0);
}

/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Sat Mar  8 22:05:49 2014 guerot_a
*/

#include "epikong.h"
#define PERIOD_FPS	(1000 / 50)

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
  manage_game_check(map, objlist);
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
  Uint32	lasttime;
  Uint32	tmptime;
  t_map		map;
  t_objlist	objlist;
  SDL_Surface*	screen;
  int		still;

  screen = epikong_init(filename, &map, &objlist);
  still = 1;
  lasttime = SDL_GetTicks();
  while (still)
    {
      still = manage_game(&map, &objlist);
      draw_game(&map, &objlist, screen);
      tmptime = SDL_GetTicks();
      if (tmptime - lasttime < PERIOD_FPS)
      	SDL_Delay(tmptime - lasttime);
      lasttime = tmptime;
    }
}

int	main(int ac, char** av)
{
  if (ac >= 2)
    epikong(av[1]);
  return (0);
}

/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Sat Mar  8 15:07:54 2014 guerot_a
*/

#include "epikong.h"

void	epikong(char* filename)
{
  t_map		map;
  t_objlist	objlist;
  SDL_Surface*	screen;
  int		still;

  memset(&objlist, 0, sizeof(t_objlist));
  load_map(filename, &map);
  load_gameobject(&map, &objlist);
  load_sprites();

  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(map.width * CASE_SIZE,
			    map.height * CASE_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  still = 1;
  while (still)
    {
      still = manage_event(&map, &objlist);
      manage_physics(&map, &objlist);
      manage_ia(&map, &objlist);
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
      draw_map(&map, screen);
      draw_gameobject(&objlist, screen);
      SDL_Flip(screen);
    }
}

int	main(int ac, char** av)
{
  if (ac >= 2)
    epikong(av[1]);
  return (0);
}

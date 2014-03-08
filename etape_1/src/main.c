/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Sat Mar  8 12:50:52 2014 guerot_a
*/

#include "epikong.h"

#define CASE_SIZE 16

void	draw_sprite_aligned(SDL_Surface* sprite, int x_case,
			    int y_case, SDL_Surface* screen)
{
  SDL_Rect	rect;

  rect.x = CASE_SIZE * x_case;
  rect.y = CASE_SIZE * y_case;
  SDL_BlitSurface(sprite, NULL, screen, &rect);
}

void	draw_map(t_map* map, SDL_Surface* screen)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  while (y < map->height)
    {
      x = 0;
      while (x < map->width)
	{
	  draw_sprite_aligned(get_sprite_by_char(map->data[y][x]), x, y, screen);
	  x++;
	}
      y++;
    }
}

void	epikong(char* filename)
{
  t_map		map;
  SDL_Surface*	screen;
  SDL_Event	event;
  int		still;

  load_map(filename, &map);
  load_sprites();

  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(map.width * CASE_SIZE,
			    map.height * CASE_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  still = 1;
  while (still)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	still = 0;
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
      draw_map(&map, screen);
      SDL_Flip(screen);
    }
}

int	main(int ac, char** av)
{
  if (ac >= 2)
    epikong(av[1]);
  return (0);
}

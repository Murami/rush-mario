/*
** draw.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:52:17 2014 guerot_a
** Last update Sun Mar  9 20:36:05 2014 guerot_a
*/

#include "epikong.h"

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

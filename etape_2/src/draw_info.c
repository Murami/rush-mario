/*
** draw_info.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 01:27:28 2014 guerot_a
** Last update Sun Mar  9 01:49:16 2014 guerot_a
*/

#include "epikong.h"

void	draw_info(t_objlist *objlist, SDL_Surface* screen, SDL_Surface* zone_infos)
{
  SDL_Rect	rect;

  (void) objlist;
  rect.x = 0;
  rect.y = screen->h - HEIGHT_INFOS;
  SDL_FillRect(zone_infos, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(zone_infos, NULL, screen, &rect);
}

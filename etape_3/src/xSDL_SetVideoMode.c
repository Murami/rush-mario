/*
** xSDL_SetVideoMode.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 16:03:46 2014 guerot_a
** Last update Sun Mar  9 13:35:40 2014 guerot_a
*/

#include "epikong.h"

SDL_Surface*	xSDL_SetVideoMode(int w, int h, int bpp, uint32_t flags)
{
  SDL_Surface*	screen;

  screen = SDL_SetVideoMode(w, h, bpp, flags);
  if (!screen)
    xabort("error: can't load screen");
  return (screen);
}

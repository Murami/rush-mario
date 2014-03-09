/*
** xSDL_LoadBMP.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:29:26 2014 guerot_a
** Last update Sat Mar  8 01:28:02 2014 guerot_a
*/

#include "epikong.h"

SDL_Surface*	xSDL_LoadBMP(char* filename)
{
  SDL_Surface*	img;

  if ((img = SDL_LoadBMP(filename)) == NULL)
    {
      fprintf(stderr, "error: image %s not found\n", filename);
      exit(EXIT_FAILURE);
    }
  return (img);
}

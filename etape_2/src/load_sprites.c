/*
** load_sprites.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:11:15 2014 guerot_a
** Last update Sat Mar  8 17:21:52 2014 genes_k
*/

#include "epikong.h"

t_spritepair sprites[] =
  {
    {'w', "Wall", NULL},
    {'s', "Ladder", NULL},
    {'i', "Mario", NULL},
    {'m', "Monster", NULL},
    {'k', "Key", NULL},
    {'o', "Exit", NULL},
    {'\0', "", NULL}
  };

void	load_sprites()
{
  sprites[0].img = xSDL_LoadBMP("Sprites/Wall.bmp");
  sprites[1].img = xSDL_LoadBMP("Sprites/Ladder.bmp");
  sprites[2].img = xSDL_LoadBMP("Sprites/Mario_1.bmp");
  sprites[3].img = xSDL_LoadBMP("Sprites/Turtle.bmp");
  sprites[4].img = xSDL_LoadBMP("Sprites/Key.bmp");
  sprites[5].img = xSDL_LoadBMP("Sprites/Exit.bmp");
  SDL_SetColorKey(sprites[1].img, SDL_SRCCOLORKEY,
		  SDL_MapRGB(sprites[1].img->format, 255, 0, 186));
  SDL_SetColorKey(sprites[2].img, SDL_SRCCOLORKEY,
		  SDL_MapRGB(sprites[2].img->format, 255, 0, 186));
  SDL_SetColorKey(sprites[3].img, SDL_SRCCOLORKEY,
		  SDL_MapRGB(sprites[3].img->format, 255, 0, 186));
  SDL_SetColorKey(sprites[4].img, SDL_SRCCOLORKEY,
		  SDL_MapRGB(sprites[4].img->format, 255, 0, 186));
}

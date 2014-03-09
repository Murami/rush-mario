/*
** menu.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sun Mar  9 00:52:42 2014 SADOWSKI Geoffroy
** Last update Sun Mar  9 22:21:44 2014 genes_k
*/

#include "epikong.h"

const char*	stages[5] =
  {
    "map/stage1.map",
    "map/stage2.map",
    "map/stage3.map",
    "map/stage4.map",
    "map/stage5.map"
  };

static int	manage_stages()
{
  SDL_Event	event;
  int		dead;
  int		stage;

  dead = 0;
  SDL_WaitEvent(&event);
  if (event.type == SDL_QUIT)
    return (0);
  if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (0);
      stage = event.key.keysym.sym - SDLK_KP1;
      while (!dead && stage < 5 && stage >= 0)
	{
	  dead = !run_stage(stages[stage]);
	  stage++;
	}
    }
  return (1);
}

static SDL_Surface*	menu_init()
{
  SDL_Surface*	menuimg;
  SDL_Surface*	screen;

  menuimg = xSDL_LoadBMP("Sprites/Menu.bmp");
  screen = xSDL_SetVideoMode(menuimg->w, menuimg->h,
			     32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_BlitSurface(menuimg, NULL, screen, NULL);
  return (screen);
}

void	epikong_menu()
{
  int		still;
  SDL_Surface*	screen;

  screen = menu_init();
  still = 1;
  while (still)
    {
      SDL_Flip(screen);
      still = manage_stages();
      screen = menu_init();
    }
}

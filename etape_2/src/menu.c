/*
** menu.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sun Mar  9 00:52:42 2014 SADOWSKI Geoffroy
<<<<<<< HEAD
** Last update Sun Mar  9 21:18:58 2014 genes_k
=======
** Last update Sun Mar  9 21:06:21 2014 SADOWSKI Geoffroy
>>>>>>> 375e79cbe0fc1080198108334041c583dcb3eca8
*/

#include "epikong.h"

const char*	stages[5] =
  {
    "map/stage17.map",
    "map/stage16.map",
    "map/stage12.map",
    "map/stage14.map",
    "map/stage15.map"
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

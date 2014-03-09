/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Sun Mar  9 03:00:18 2014 guerot_a
*/

#include "epikong.h"

SDL_Surface*	epikong_init(char* filename, t_map* map, t_objlist* objlist, SDL_Surface** surface)
{
  memset(objlist, 0, sizeof(t_objlist));
  load_map(filename, map);
  load_gameobject(map, objlist);
  *surface = SDL_CreateRGBSurface(0, map->width * CASE_SIZE, HEIGHT_INFOS, 32, 0, 0, 0, 0);
  return (xSDL_SetVideoMode(map->width * CASE_SIZE,
			    map->height * CASE_SIZE + HEIGHT_INFOS, 32, SDL_HWSURFACE | SDL_DOUBLEBUF));
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

void	draw_game(t_map* map, t_objlist* objlist, SDL_Surface* screen, SDL_Surface* infos_zone)
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  draw_map(map, screen);
  draw_gameobject(objlist, screen);
  draw_info(objlist, screen, infos_zone);
  SDL_Flip(screen);
}

char*	stages[5] =
  {
    "map/stage9.map",
    "map/stage9.map",
    "map/stage9.map",
    "map/stage9.map",
    "map/stage1.map"
  };

int	run_stage(char *filename)
{
  Uint32	lasttime;
  Uint32	tmptime;
  t_map		map;
  t_objlist	objlist;
  SDL_Surface*	screen;
  SDL_Surface*	infos_zone;
  int		still;

  screen = epikong_init(filename, &map, &objlist, &infos_zone);
  still = 1;
  lasttime = SDL_GetTicks();
  while (still && !objlist.cleared)
    {
      still = manage_game(&map, &objlist);
      draw_game(&map, &objlist, screen, infos_zone);
      tmptime = SDL_GetTicks();
      if (tmptime - lasttime < PERIOD_FPS)
      	SDL_Delay(tmptime - lasttime);
      lasttime = tmptime;
    }
  if (!still)
    return (0);
  return (1);
}

int	manage_stages()
{
  SDL_Event	event;
  int		dead;
  int		stage;

  dead = 0;
  SDL_WaitEvent(&event);
  if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (0);
      stage = event.key.keysym.sym - SDLK_KP1;
      while (!dead && stage < 5)
	{
	  dead = !run_stage(stages[stage]);
	  stage++;
	}
    }
  return (1);
}

SDL_Surface*	menu_init()
{
  SDL_Surface*	menuimg;
  SDL_Surface*	screen;

  menuimg = xSDL_LoadBMP("Sprites/Menu.bmp");
  screen = xSDL_SetVideoMode(menuimg->w, menuimg->h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
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

void	load_ressources()
{
  SDL_Init(SDL_INIT_VIDEO);
  load_sprites();
}

int	main(int ac, char** av)
{
  load_ressources();
  epikong_menu();
  return (0);
}

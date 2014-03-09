/*
** game.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:11:51 2014 guerot_a
** Last update Sun Mar  9 20:18:33 2014 guerot_a
*/

#include "epikong.h"

static SDL_Surface*	epikong_init(const char* filename, t_map* map,
			     t_objlist* objlist, SDL_Surface** surface)
{
  memset(objlist, 0, sizeof(t_objlist));
  load_map(filename, map);
  load_gameobject(map, objlist);
  *surface = SDL_CreateRGBSurface(0, map->width * CASE_SIZE,
				  HEIGHT_INFOS, 32, 0, 0, 0, 0);
  return (xSDL_SetVideoMode(map->width * CASE_SIZE,
			    map->height * CASE_SIZE + HEIGHT_INFOS,
			    32, SDL_HWSURFACE | SDL_DOUBLEBUF));
}

static int	manage_game(t_map* map, t_objlist* objlist)
{
  int	still;

  still = manage_event(map, objlist);
  manage_game_check(map, objlist);
  manage_ia(map, objlist);
  manage_game_check(map, objlist);
  manage_physics(map, objlist);
  return (still);
}

static void	draw_game(t_map* map, t_objlist* objlist, SDL_Surface* screen,
		  SDL_Surface* infos_zone)
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  draw_map(map, screen);
  draw_gameobject(objlist, screen);
  draw_info(objlist, screen, infos_zone);
  SDL_Flip(screen);
}

int	run_stage(const char *filename, int bossstage)
{
  Uint32	lasttime;
  Uint32	tmptime;
  t_map		map;
  t_objlist	objlist;
  SDL_Surface*	screen;
  SDL_Surface*	infos_zone;
  int		still;

  screen = epikong_init(filename, &map, &objlist, &infos_zone);
  objlist.bosslvl = bossstage;
  still = 1;
  lasttime = SDL_GetTicks();
  while (still && !objlist.cleared && objlist.player.life)
    {
      still = manage_game(&map, &objlist);
      draw_game(&map, &objlist, screen, infos_zone);
      tmptime = SDL_GetTicks();
      if (tmptime - lasttime < PERIOD_FPS)
      	SDL_Delay(tmptime - lasttime);
      lasttime = tmptime;
    }
  free_events();
  if (!still || !objlist.player.life)
    return (0);
  return (1);
}

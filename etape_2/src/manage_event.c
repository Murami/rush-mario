/*
** manage_event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:01:46 2014 guerot_a
** Last update Sat Mar  8 21:38:45 2014 SADOWSKI Geoffroy
*/

#include "epikong.h"

#define PERIOD_INPUT 100

int keys[512];

static void	manage_event_by_key(t_map* map, t_objlist* objlist, SDLKey key)
{
  if (key == SDLK_SPACE)
    mario_jump(map, objlist);
  else if (key == SDLK_a)
    mario_jump_left(map, objlist);
  else if (key == SDLK_e)
    mario_jump_right(map, objlist);
  else if (key == SDLK_RIGHT)
    mario_right(map, objlist);
  else if (key == SDLK_LEFT)
    mario_left(map, objlist);
  else if (key == SDLK_UP)
    mario_up(map, objlist);
  else if (key == SDLK_DOWN)
    mario_down(map, objlist);
}

static void	manage_event_mapped(t_map* map, t_objlist* objlist)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (keys[i])
	{
	  manage_event_by_key(map, objlist, i);
	}
      i++;
    }
}

static int	manage_event_key(t_map* map, t_objlist* objlist, SDLKey key)
{
  if (key == SDLK_ESCAPE)
    return (0);
  else
    keys[key] = 1;
  return (1);
}

int	manage_event(t_map* map, t_objlist* objlist)
{
  static Uint32	lasttime = 0;
  Uint32	currtime;
  SDL_Event	event;
  int		still;

  still = 1;
  currtime = SDL_GetTicks();
  if (currtime - lasttime < PERIOD_INPUT)
    return (1);
  lasttime = currtime;
  memset(keys, 0, 512 * sizeof(int));
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return (0);
      if (event.type == SDL_KEYDOWN)
	still = manage_event_key(map, objlist, event.key.keysym.sym);
    }
  manage_event_mapped(map, objlist);
  return (still);
}

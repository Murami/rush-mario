/*
** manage_event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:01:46 2014 guerot_a
** Last update Sat Mar  8 17:07:34 2014 guerot_a
*/

#include "epikong.h"

#define PERIOD_INPUT 100

static int	manage_event_key(t_map* map, t_objlist* objlist, SDLKey key)
{
  SDL_Event	event;

  if (key == SDLK_ESCAPE)
    return (0);
  /* ptr func ici !!! */
  else if (key == SDLK_LEFT)
    mario_left(map, objlist);
  else if (key == SDLK_RIGHT)
    mario_right(map, objlist);
  else if (key == SDLK_UP)
    mario_up(map, objlist);
  else if (key == SDLK_DOWN)
    mario_down(map, objlist);
  else
    return (1);
  /**/
  while (SDL_PollEvent(&event));
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
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return (0);
      if (event.type == SDL_KEYDOWN)
	still = manage_event_key(map, objlist, event.key.keysym.sym);
    }
  return (still);
}

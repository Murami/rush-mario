/*
** manage_event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:01:46 2014 guerot_a
** Last update Sat Mar  8 15:02:58 2014 guerot_a
*/

#include "epikong.h"

static int	manage_event_key(t_map* map, t_objlist* objlist, SDLKey key)
{
  if (key == SDLK_ESCAPE)
    return (0);
  /* ptr func ici !!! */
  if (key == SDLK_LEFT)
    mario_left(map, objlist);
  if (key == SDLK_RIGHT)
    mario_right(map, objlist);
  if (key == SDLK_UP)
    mario_up(map, objlist);
  if (key == SDLK_DOWN)
    mario_down(map, objlist);
  /**/
  return (1);
}

int	manage_event(t_map* map, t_objlist* objlist)
{
  SDL_Event	event;

  SDL_WaitEvent(&event);
  if (event.type == SDL_QUIT)
    return (0);
  if (event.type == SDL_KEYDOWN)
    return (manage_event_key(map, objlist, event.key.keysym.sym));
  return (1);
}

/*
** manage_event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:01:46 2014 guerot_a
** Last update Sun Mar  9 16:31:13 2014 guerot_a
*/

#include "epikong.h"

int	manage_event(t_map* map, t_objlist* objlist)
{
  SDL_Event	event;
  int		still;

  still = 1;
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT ||
	  (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
	  return (0);
      if (event.type == SDL_KEYDOWN)
	add_pressed(event.key.keysym.sym);
      else if (event.type == SDL_KEYUP)
	add_released(event.key.keysym.sym);
    }
  run_events(map, objlist);
  clear_events();
  return (still);
}

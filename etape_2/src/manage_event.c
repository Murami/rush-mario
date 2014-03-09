/*
** manage_event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:01:46 2014 guerot_a
** Last update Sun Mar  9 15:18:08 2014 guerot_a
*/

#include "epikong.h"

t_event	events[] =
  {
    {SDLK_SPACE	, 0, 0, 0, &mario_jump},
    {SDLK_KP7	, 0, 0, 0, &mario_jump_left},
    {SDLK_KP9	, 0, 0, 0, &mario_jump_right},
    {SDLK_KP4	, 0, 0, 0, &mario_left},
    {SDLK_KP6	, 0, 0, 0, &mario_right},
    {SDLK_KP8	, 0, 0, 0, &mario_up},
    {SDLK_KP5	, 0, 0, 0, &mario_down},
    {SDLK_f, 0, 0, 0, &mario_fire},
    {0, 0, 0, 0, NULL}
  };

static void	add_pressed(SDLKey key)
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      if (events[i].key == key)
	events[i].pressed++;
      i++;
    }
}

static void	add_released(SDLKey key)
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      if (events[i].key == key)
	events[i].released++;
      i++;
    }
}

static void	run_events(t_map* map, t_objlist* objlist)
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      if ((events[i].active && !events[i].released) || events[i].pressed)
	events[i].func(map, objlist);
      i++;
    }
}

static void	clear_events()
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      events[i].pressed = (events[i].pressed - events[i].released > 0) ?
	1 : events[i].pressed == 1;
      events[i].released = (events[i].released - events[i].pressed > 0) ?
	1 : events[i].released == 1;
      if ((events[i].pressed && !events[i].released && !events[i].active) ||
	  (!events[i].pressed && events[i].released && events[i].active))
	events[i].active = !events[i].active;
      events[i].pressed = 0;
      events[i].released = 0;
      i++;
    }
}

void	free_events()
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      events[i].active = 0;
      events[i].pressed = 0;
      events[i].released = 0;
      i++;
    }
}

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

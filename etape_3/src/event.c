/*
** event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:28:45 2014 guerot_a
** Last update Sun Mar  9 16:31:10 2014 guerot_a
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

void	add_pressed(SDLKey key)
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

void	add_released(SDLKey key)
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

void	run_events(t_map* map, t_objlist* objlist)
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

void	clear_events()
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

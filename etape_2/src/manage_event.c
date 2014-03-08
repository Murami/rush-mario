/*
** manage_event.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:01:46 2014 guerot_a
** Last update Sat Mar  8 22:06:06 2014 guerot_a
*/

#include "epikong.h"

t_event	events[] =
  {
    {SDLK_SPACE	, 0, 0, 0, &mario_jump},
    {SDLK_LEFT	, 0, 0, 0, &mario_left},
    {SDLK_RIGHT	, 0, 0, 0, &mario_right},
    {SDLK_UP	, 0, 0, 0, &mario_up},
    {SDLK_DOWN	, 0, 0, 0, &mario_down},
    {0, 0, 0, 0, NULL}
  };

static void	add_pressed(SDLKey key)
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      if (events[i].key == key)
	{
	  if (i == 1)
	    printf("left pre\n");
	  events[i].pressed++;
	}
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
	{
	  if (i == 1)
	    printf("left rel\n");
	  events[i].released++;
	}
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
      if (i == 1 && events[i].active)
	printf("dafuck\n");
      i++;
    }
}

static void	clear_events()
{
  int		i;

  i = 0;
  while (events[i].func)
    {
      events[i].pressed = (events[i].pressed - events[i].released > 0) ? 1 : events[i].pressed == 1;
      events[i].released = (events[i].released - events[i].pressed > 0) ? 1 : events[i].released == 1;
      if ((events[i].pressed && !events[i].released && !events[i].active) ||
	  (!events[i].pressed && events[i].released && events[i].active))
	events[i].active = !events[i].active;
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
      if (event.type == SDL_KEYUP)
	add_released(event.key.keysym.sym);
    }
  run_events(map, objlist);
  clear_events();
  return (still);
}

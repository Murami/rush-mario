/*
** sprite_pair.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:34:57 2014 guerot_a
** Last update Sat Mar  8 00:47:15 2014 guerot_a
*/

#include "epikong.h"

SDL_Surface*	get_sprite_by_char(uint32_t key)
{
  int		i;

  i = 0;
  while (sprites[i].img)
    {
      if (sprites[i].key_char == key)
	return (sprites[i].img);
      i++;
    }
  return (NULL);
}

SDL_Surface*	get_sprite_by_str(char* key)
{
  int		i;

  i = 0;
  while (sprites[i].img)
    {
      if (strcmp(sprites[i].key_str, key) == 0)
	return (sprites[i].img);
      i++;
    }
  return (NULL);
}

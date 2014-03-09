/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Sun Mar  9 16:12:15 2014 guerot_a
*/

#include "epikong.h"

void	load_ressources()
{
  SDL_Init(SDL_INIT_VIDEO);
  load_sprites();
}

int	main()
{
  load_ressources();
  epikong_menu();
  return (0);
}

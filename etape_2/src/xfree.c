/*
** xfree.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:41:24 2014 guerot_a
** Last update Fri Mar  7 21:45:36 2014 guerot_a
*/

#include "dependencies.h"

void	_xfree(void** ptr)
{
  free(*ptr);
  *ptr = NULL;
}

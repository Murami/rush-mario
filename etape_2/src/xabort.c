/*
** xabort.c for  in /home/guerot_a/depots/T2Rush1/etape_1/src
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:46:02 2014 guerot_a
** Last update Fri Mar  7 21:46:02 2014 guerot_a
*/

#include "dependencies.h"

void	xabort(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}

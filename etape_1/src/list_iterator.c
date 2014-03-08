/*
** list_iterator.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 23:17:13 2014 guerot_a
** Last update Fri Mar  7 23:34:48 2014 guerot_a
*/

#include "epikong.h"

t_listit	list_begin(t_list list)
{
  return (list->next);
}

t_listit	list_end(t_list list)
{
  return (list);
}

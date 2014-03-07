/*
** epikong.h for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:47:03 2014 guerot_a
** Last update Fri Mar  7 21:48:15 2014 guerot_a
*/

#ifndef EPIKONG_H
# define EPIKONG_H

# define _POSIX_C_SOURCE
# define _XOPEN_SOURCE

# include "dependencies.h"

#define xfree(ptr)	_xfree((void**)ptr)
void	_xfree(void** ptr);

void	xabort(char *str);

#endif /* EPIKONG_H */

/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Fri Mar  7 21:31:34 2014 guerot_a
*/

#define _POSIX_C_SOURCE
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>

/*
** Cast define for xfree
*/
#define xfree(ptr)	_xfree((void**)ptr)

void	_xfree(void** ptr)
{
  free(*ptr);
  *ptr = NULL;
}

void	xabort(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}

void	epikong(char* filename)
{
  FILE*		mapfile;
  char*		str;
  size_t	nread;

  mapfile = fopen(filename, "r");
  if (mapfile == NULL)
    xabort("error: can't open map given in parameter");

  str = NULL;
  while (getline(&str, &nread, mapfile) != -1)
    {
      printf("%s", str);
      xfree(&str);
    }
  fclose(mapfile);
}

int	main(int ac, char** av)
{
  if (ac >= 2)
    epikong(av[1]);
  return (0);
}

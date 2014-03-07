/*
** main.c for  in /home/guerot_a/depots/T2Rush1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 20:33:05 2014 guerot_a
** Last update Fri Mar  7 21:43:53 2014 guerot_a
*/

#include "epikong.h"

/*
** Cast define for xfree
*/

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

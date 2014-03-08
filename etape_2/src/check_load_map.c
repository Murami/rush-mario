/*
** check_load_map.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 12:52:55 2014 guerot_a
** Last update Sat Mar  8 20:55:57 2014 genes_k
*/

#include "epikong.h"

char	valid_char[] =
  {
    '.',
    'o',
    'w',
    'k',
    'i',
    's',
    'm',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '\0'
  };

static void	test_valid_char(char key)
{
  int		i;

  i = 0;
  while (valid_char[i])
    {
      if (valid_char[i] == key)
	return;
      i++;
    }
  xabort("error: invalid map: unknown object found");
}

static void	check_line_wall(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != 'w')
	xabort("error: invalid map: map is leaked");
      i++;
    }
}

static void	update_verif(char mapkey[3], int mapval[3], char key)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      if (mapkey[i] == key)
	mapval[i]++;
      i++;
    }
}

static void	verif_line(char *line, int width, char* mapkey, int* mapval)
{
  int		x;

  if (line[0] != 'w' ||
      line[strlen(line) - 1] != 'w')
    xabort("error: invalid map: map is leaked");
  x = 0;
  while (x < width)
    {
      update_verif(mapkey, mapval, line[x]);
      test_valid_char(line[x]);
      x++;
    }
}

void		verif_map(t_map *map)
{
  char			mapkey[3];
  int			mapval[3];
  unsigned int		y;

  strncpy(mapkey, "koi", 3);
  memset(mapval, 0, 3 * sizeof(int));
  check_line_wall(map->data[0]);
  check_line_wall(map->data[map->height - 1]);
  y = 0;
  while (y < map->height)
    {
      verif_line(map->data[y], map->width, mapkey, mapval);
      y++;
    }
  if (mapval[0] != 1 || mapval[1] != 1 || mapval[2] != 1)
    {
      fprintf(stderr,
	      "error: error with game items (%d-%d-%d)\n",
	      mapval[0], mapval[1], mapval[2]);
      exit(EXIT_FAILURE);
    }
}

/*
** epikong.h for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:47:03 2014 guerot_a
** Last update Sun Mar  9 03:26:08 2014 guerot_a
*/

#ifndef EPIKONG_H
# define EPIKONG_H

# define _POSIX_C_SOURCE
# define _XOPEN_SOURCE

# define CASE_SIZE	16
# define PERIOD_FPS	(1000 / 50)
# define HEIGHT_INFOS	50

# include "dependencies.h"

# include "map.h"
# include "sprite.h"
# include "list.h"
# include "pair.h"
# include "objlist.h"

# define	xfree(ptr)	_xfree((void**)ptr)
void		_xfree(void** ptr);
void		xabort(char *str);
void*		xmalloc(size_t n);
SDL_Surface*	xSDL_LoadBMP(char* filename);
SDL_Surface*	xSDL_SetVideoMode(int w, int h, int bpp, uint32_t flags);

void	load_map(char* filename, t_map* map);
void	load_sprites();
void	load_gameobject(t_map* map, t_objlist* objlist);
void	verif_map(t_map* map);

SDL_Surface*	get_sprite_by_char(uint32_t key);
SDL_Surface*	get_sprite_by_str(char* key);

void	draw_map(t_map* map, SDL_Surface* screen);
void	draw_gameobject(t_objlist* list, SDL_Surface* screen);
void	draw_info(t_objlist* list, SDL_Surface* screen, SDL_Surface* zone_infos);

int	manage_event(t_map* map, t_objlist* objlist);
void	manage_physics(t_map* map, t_objlist* objlist);
void	manage_ia(t_map* map, t_objlist* objlist);
void    manage_game_check(t_map *map, t_objlist *objlist);
void    manage_game_check_xy(t_map *map, t_objlist *objlist, int x, int y);

int	mario_can_walk(t_map* map, int x, int y);
void	mario_left(t_map* map, t_objlist* objlist);
void	mario_right(t_map* map, t_objlist* objlist);
void	mario_up(t_map* map, t_objlist* objlist);
void	mario_down(t_map* map, t_objlist* objlist);
void	mario_jump(t_map* map, t_objlist* objlist);
void	mario_jump_left(t_map* map, t_objlist* objlist);
void	mario_jump_right(t_map* map, t_objlist* objlist);
void	mario_die(t_objlist* objlist);

void	free_events();

#endif /* EPIKONG_H */

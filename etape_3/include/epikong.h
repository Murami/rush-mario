/*
** epikong.h for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:47:03 2014 guerot_a
** Last update Sun Mar  9 18:48:55 2014 guerot_a
*/

#ifndef EPIKONG_H
# define EPIKONG_H

# define _POSIX_C_SOURCE
# define _XOPEN_SOURCE

# define CASE_SIZE		16
# define PERIOD_FPS		(1000 / 50)
# define HEIGHT_INFOS		50
# define OFFSET_LEFT_LIFE	20
# define PADDING_LIFE		10
# define PERIOD_FALL		75
# define PERIOD_JUMP		75
# define PERIOD_WALK		150
# define PERIOD_FIRE		500
# define MARIO_PERIOD_WALK	60
# define DIR_DELAY		1000
# define COLOR_ALPHA		SDL_MapRGB(sprites[i].img->format, 255, 0, 186)
# define OFFSET_LEFT_KEY	200
# define OFFSET_LEFT_GUN	220
# define PERIOD_RUN_PROJ	50
# define IS_WALL(a)		(strchr("wcr12345678", a))

# include "dependencies.h"

# include "map.h"
# include "sprite.h"
# include "list.h"
# include "pair.h"
# include "objlist.h"

void		epikong_menu();
int		run_stage(const char *filename);

/*
** x functions
*/

void		xabort(char *str);
void*		xmalloc(size_t n);
SDL_Surface*	xSDL_LoadBMP(char* filename);
SDL_Surface*	xSDL_SetVideoMode(int w, int h, int bpp, uint32_t flags);

/*
** Load ressources
*/

void		load_mario(int x, int y, t_objlist* objlist);
void		load_monster(int x, int y, t_objlist* objlist);
void		load_monster2(int x, int y, t_objlist* objlist);
void		load_map(const char* filename, t_map* map);
void		load_sprites();
void		load_gameobject(t_map* map, t_objlist* objlist);
void		verif_map(t_map* map);

/*
** Draw
*/

void		draw_sprite_aligned(SDL_Surface* sprite, int x_case,
				    int y_case, SDL_Surface* screen);
void		draw_map(t_map* map, SDL_Surface* screen);
void		draw_gameobject(t_objlist* list, SDL_Surface* screen);
void		draw_info(t_objlist* list, SDL_Surface* screen,
			  SDL_Surface* zone_infos);

/*
** Events managers
*/

void		add_pressed(SDLKey key);
void		add_released(SDLKey key);
void		run_events(t_map* map, t_objlist* objlist);
void		clear_events();
void		free_events();

/*
** Game main loop manager
*/

int		manage_event(t_map* map, t_objlist* objlist);
void		manage_physics(t_map* map, t_objlist* objlist);
void		manage_ia(t_map* map, t_objlist* objlist);
void		manage_game_check(t_map *map, t_objlist *objlist);
void		manage_game_check_xy(t_map *map, t_objlist *objlist, int x, int y);
t_listit	monster_hit_projectile(t_objlist* objlist, t_listit monster_it);
void		manage_projectile(t_map* map, t_objlist* objlist);

/*
** Mario events/actions
*/

int		mario_manage_walk_time(t_objlist* objlist);
int		mario_can_walk(t_map* map, int x, int y);
void		mario_left(t_map* map, t_objlist* objlist);
void		mario_right(t_map* map, t_objlist* objlist);
void		mario_up(t_map* map, t_objlist* objlist);
void		mario_down(t_map* map, t_objlist* objlist);
void		mario_jump(t_map* map, t_objlist* objlist);
void		mario_jump_left(t_map* map, t_objlist* objlist);
void		mario_jump_right(t_map* map, t_objlist* objlist);
void		mario_jumping(t_map* map, t_objlist* objlist);
void		mario_takekey(t_map* map, t_objlist* objlist);
void		mario_die(t_objlist* objlist);
void		mario_fire(t_map* map, t_objlist* objlist);

/*
** Interactions with game objects
*/

void		take_gun(t_map* map, t_objlist* list, int x, int y);
void		take_life(t_map* map, t_objlist* list, int x, int y);
void		take_key(t_map* map, t_objlist* list, int x, int y);
void		use_door(t_map* map, t_objlist* list, int x, int y);
void		take_trap(t_map* map, t_objlist* list, int x, int y);
/*
** Utility
*/

SDL_Surface*	get_sprite_by_char(uint32_t key);
SDL_Surface*	get_sprite_by_str(char* key);

#endif /* EPIKONG_H */

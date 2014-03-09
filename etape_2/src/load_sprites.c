/*
** load_sprites.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:11:15 2014 guerot_a
** Last update Sun Mar  9 18:10:28 2014 guerot_a
*/

#include "epikong.h"

t_spritepair sprites[] =
  {
    {'w', "Wall"		, "Sprites/Wall.bmp", NULL},
    {'s', "Ladder"		, "Sprites/Ladder.bmp", NULL},
    {'i', "Mario"		, "Sprites/Mario_1.bmp", NULL},
    {'i', "MarioBack"		, "Sprites/Mario_Back_1.bmp", NULL},
    {'i', "MarioJump"		, "Sprites/Mario_Jump.bmp", NULL},
    {'i', "MarioJumpBack"	, "Sprites/Mario_Jump_Back.bmp", NULL},
    {'m', "Monster"		, "Sprites/Turtle.bmp", NULL},
    {'m', "MonsterBack"		, "Sprites/Turtle_Back.bmp", NULL},
    {'k', "Key"			, "Sprites/Key.bmp", NULL},
    {'o', "Exit"		, "Sprites/Exit.bmp", NULL},
    {'1', "Corner_TL"		, "Sprites/Pipe_Corner_TL.bmp", NULL},
    {'2', "Top"			, "Sprites/Pipe_Top.bmp", NULL},
    {'3', "Corner_TR"		, "Sprites/Pipe_Corner_TR.bmp", NULL},
    {'4', "Left"		, "Sprites/Pipe_Left.bmp", NULL},
    {'5', "Right"		, "Sprites/Pipe_Right.bmp", NULL},
    {'6', "Corner_BL"		, "Sprites/Pipe_Corner_BL.bmp", NULL},
    {'7', "Bot"			, "Sprites/Pipe_Bot.bmp", NULL},
    {'8', "Corner_BR"		, "Sprites/Pipe_Corner_BR.bmp", NULL},
    {'d', "Death"		, "Sprites/Mario_Death.bmp", NULL},
    {'l', "Life"		, "Sprites/Life.bmp", NULL},
    {'g', "Gun"			, "Sprites/Flower_Fire.bmp", NULL},
    {'p', "Projectile"		, "Sprites/Fire.bmp", NULL},
    {'M', "Monster2"		, "Sprites/Monster.bmp", NULL},
    {'M', "MonsterBack2"	, "Sprites/Monster_Back.bmp", NULL},
    {'c', "Cloud"		, "Sprites/Cloud_Platform.bmp", NULL},
    {'r', "Iron"		, "Sprites/Iron_Platform.bmp", NULL},
    {'x', "Explosion"		, "Sprites/Explosion.bmp", NULL},
    {'B', "Boss"		, "Sprites/Anti_Mario.bmp", NULL},
    {'B', "BossBack"		, "Sprites/Anti_Mario_Back.bmp", NULL},
    {'t', "Trap_up"		, "Sprites/Trap_Up.bmp", NULL},
    {'\0', ""			, "", NULL}
  };

void	load_sprites()
{
  int	i;

  i = 0;
  while (sprites[i].key_char)
    {
      sprites[i].img = xSDL_LoadBMP(sprites[i].filename);
      SDL_SetColorKey(sprites[i].img, SDL_SRCCOLORKEY, COLOR_ALPHA);
      i++;
    }
}

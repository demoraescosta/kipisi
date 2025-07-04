#pragma once
#include <raylib/raylib.h>
#include "sprites.h"

typedef struct Player 
{
    unsigned int x;
    unsigned int y;

    unsigned int health;
    unsigned int gold;

    SpriteImage sprite;
} Player;

typedef struct GameState
{
    Player p;

    Texture2D sprite_sheet;
} GameState;


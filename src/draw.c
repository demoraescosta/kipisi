#include "draw.h"

void draw_sprite(Texture2D sheet, Rectangle sprite, int x, int y)
{
    DrawTexturePro(sheet, sprite, (Rectangle){ 0, 0, SPRITE_SIZE, SPRITE_SIZE }, (Vector2){ SPRITE_SIZE * x, SPRITE_SIZE * y }, 0.0f, WHITE);
}


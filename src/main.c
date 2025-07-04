#include <stdio.h>

#include "sprites.h"
#include "game.h"
#include "draw.h"

#define ROWS 32
#define COLS 28

int main(int argc, char** argv) 
{
    printf("toki ma!\n");

    const unsigned int scale = 4;

    const int logical_width = ROWS * SPRITE_SIZE; 
    const int logical_height = COLS * SPRITE_SIZE; 
    const int screen_width = ROWS * SPRITE_SIZE * scale; 
    const int screen_height = COLS * SPRITE_SIZE * scale;
    InitWindow(screen_width, screen_height, "kipisi");

    Texture2D sitelen_pona = LoadTexture("res/sitelenpona.png");

    Player p = {
        .x = 0,
        .y = 0,

        .sprite = SITELEN_JAN
    };

    GameState state = {
        .p = p,
        .sprite_sheet = sitelen_pona,
    };

    SetTargetFPS(60);
    Rectangle sprite_r = { 0 };
    sprite_r.x = 0;
    sprite_r.y = 0;
    sprite_r.height = SPRITE_SIZE;
    sprite_r.width  = SPRITE_SIZE;

    Rectangle target_r = { 0 };
    target_r.x = 0;
    target_r.y = 0;
    target_r.height = SPRITE_SIZE;
    target_r.width  = SPRITE_SIZE;

    RenderTexture2D target = LoadRenderTexture(logical_width, logical_height);

    unsigned long long tick = 0;
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_RIGHT)) p.x -= 1;
        if (IsKeyPressed(KEY_LEFT)) p.x += 1;
        if (IsKeyPressed(KEY_UP)) p.y += 1;
        if (IsKeyPressed(KEY_DOWN)) p.y -= 1;

        BeginTextureMode(target);
            draw_sprite(state, p.sprite, p.x, p.y);
            ClearBackground(BLACK);
        EndTextureMode();

        BeginDrawing();
            DrawTexturePro(target.texture, (Rectangle){ 0, 0, logical_width, -logical_height }, (Rectangle){ 0, 0, screen_width, screen_height }, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
        EndDrawing();

        tick += 1;
    }

    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}

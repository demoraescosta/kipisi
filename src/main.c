#include <stdio.h>
#include "raylib/raylib.h"

#include "sprites.h"

int main(int argc, char** argv) {
    printf("toki ma!\n");

    const unsigned int scale = 4;

    const int logical_width = 32 * SPRITE_SIZE; 
    const int logical_height = 28 * SPRITE_SIZE; 
    const int screen_width = 32 * SPRITE_SIZE * scale; 
    const int screen_height = 28 * SPRITE_SIZE * scale;
    InitWindow(screen_width, screen_height, "kipisi");

    Texture2D sitelen_pona = LoadTexture("res/sitelenpona.png");

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
        tick += 1;
        BeginTextureMode(target);
            /* for (int i = 0; i < 16; i++) */
            /* { */
            /*     for (int j = 0; j < 16; j++) */
            /*     { */
            /*         target_r.x = SPRITE_SIZE * j; */
            /*         sprite_r.x = SPRITE_SIZE * j; */
            /*         DrawTexturePro(sitelen_pona, sprite_r, target_r, (Vector2){ 0, 0 }, 0.0f, WHITE); */
            /*     } */
            /*     target_r.y = SPRITE_SIZE * i; */
            /*     sprite_r.y = SPRITE_SIZE * i; */
            /* } */
            draw_sprite(sitelen_pona, SITELEN_SOWELI, 0, 0);
            ClearBackground(BLACK);
        EndTextureMode();
        BeginDrawing();
            DrawTexturePro(target.texture, (Rectangle){ 0, 0, logical_width, -logical_height }, (Rectangle){ 0, 0, screen_width, screen_height }, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}

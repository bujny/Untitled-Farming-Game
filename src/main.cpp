#include <raylib.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

constexpr int screenWidth = 1920;
constexpr int screenHeight = 1080;
constexpr int fps = 60;
constexpr int fontSize = 100;

void drawUpdate()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello!", screenWidth / 2 - fontSize, screenHeight / 2 - (fontSize / 2), fontSize, RED);
    EndDrawing();
}

int main()
{
    InitWindow(screenWidth, screenHeight, "UntitledFarmingGame");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(drawUpdate, fps, 1);
#else
    SetTargetFPS(fps);
    while (!WindowShouldClose())
    {
        drawUpdate();
    }
#endif

    CloseWindow();

    return 0;
}
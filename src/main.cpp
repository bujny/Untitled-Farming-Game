#include "World.hpp"
#include "Logger.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void drawUpdate()
{
    BeginDrawing();
    ClearBackground(mapCharacteristics::kWorldBackground);
    EndDrawing();
}

int main()
{
    InitWindow(gameCharacteristics::kScreenWidth,gameCharacteristics::kScreenHeight, "UntitledFarmingGame");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(drawUpdate, fps, 1);
#else
    SetTargetFPS(gameCharacteristics::kFps);
    while (!WindowShouldClose())
    {
        drawUpdate();
    }
#endif

    CloseWindow();

    return 0;
}
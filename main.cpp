#include <raylib.h>

int main() {
    InitWindow(800, 600, "Hello Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BEIGE);
        DrawText("Hello World!", 400, 250, 50, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// compile : g++ main.cpp -o main -lraylib -lm -ldl -pthread
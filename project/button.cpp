#include "button.h"

bool DrawButton(Button b) {
    Vector2 mouse = GetMousePosition();
    bool hover = CheckCollisionPointRec(mouse, b.rect);
    Color c = hover ? LIGHTGRAY : b.color;

    DrawRectangleRec(b.rect, c);
    DrawRectangleLinesEx(b.rect, 2, DARKGRAY);
    DrawText(
        b.text,
        b.rect.x + b.rect.width / 2 - MeasureText(b.text, 20) / 2,
        b.rect.y + b.rect.height / 2 - 10,
        20,
        BLACK
    );

    return hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

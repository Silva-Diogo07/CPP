#include <raylib.h>
#include <vector>
#include <string>
using namespace std;

// ---------------- STRUCTS ----------------
struct Car {
    string name;
    int year;
    int price;
    float zeroToHundred;
    int maxSpeed;
    int cavalos;
};

struct Button {
    Rectangle rect;
    const char* text;
    Color color;
};
    
// ---------------- BUTTON ----------------
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

// ---------------- MAIN ----------------
int main() {
    InitWindow(900, 600, "Mini Jogo");
    SetTargetFPS(60);

    enum Screen { MENU, CONCESSIONARIA, GARAGEM } screen = MENU;

    int money = 999999;

    // -------- CARROS DISPONÍVEIS --------
    vector<Car> shopCars = {
        {"Supra", 1997, 100000, 1.0f, 500, 1000},
        {"Civic", 2000, 50000, 20.0f, 120, 90},
        {"Corolla", 2010, 30000, 30.0f, 90, 60}
    };

    // -------- GARAGEM --------
    vector<Car> garage;
    int shopIndex = 0;
    int garageIndex = 0;

    // -------- BOTÕES MENU --------
    Button playBtn   = {{350, 180, 200, 60}, "JOGAR", GRAY};
    Button garageBtn = {{350, 260, 200, 60}, "GARAGEM", GRAY};
    Button shopBtn   = {{350, 340, 200, 60}, "TCAR", GRAY};

    // -------- BOTÕES GERAIS --------
    Button buyBtn   = {{350, 470, 200, 50}, "COMPRAR", GREEN};
    Button backBtn  = {{20, 540, 160, 40}, "MENU", GRAY};
    Button nextBtn  = {{780, 300, 80, 40}, ">", GRAY};
    Button prevBtn  = {{40, 300, 80, 40}, "<", GRAY};

    // ---------------- LOOP ----------------
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // ================= MENU =================
        if (screen == MENU) {
            DrawText("MENU PRINCIPAL", 300, 80, 40, DARKGRAY);
            DrawText(TextFormat("Dinheiro: $%d", money), 20, 20, 20, DARKGREEN);

            DrawButton(playBtn);
            if (DrawButton(garageBtn)) screen = GARAGEM;
            if (DrawButton(shopBtn)) screen = CONCESSIONARIA;
        }

        // ================= CONCESSIONÁRIA =================
        else if (screen == CONCESSIONARIA) {
            Car& car = shopCars[shopIndex];

            DrawText("LASANHAS", 340, 30, 40, DARKGRAY);
            DrawText(TextFormat("Dinheiro: $%d", money), 20, 20, 20, DARKGREEN);

            // Placeholder do carro
            DrawRectangle(330, 120, 240, 120, BLUE);

            DrawText(TextFormat("%s (%d)", car.name.c_str(), car.year), 330, 260, 22, BLACK);
            DrawText(TextFormat("Preço: $%d", car.price), 330, 290, 20, BLACK);

            DrawText(TextFormat("0-100 km/h: %.1f s", car.zeroToHundred), 330, 330, 20, DARKGRAY);
            DrawText(TextFormat("Velocidade Max: %d km/h", car.maxSpeed), 330, 360, 20, DARKGRAY);
            DrawText(TextFormat("Potência: %d", car.cavalos), 330, 390, 20, DARKGRAY);

            if (money >= car.price) {
                if (DrawButton(buyBtn)) {
                    money -= car.price;
                    garage.push_back(car);
                }
            } else {
                DrawRectangleRec(buyBtn.rect, DARKGRAY);
                DrawText("SEM DINHEIRO", 370, 485, 18, BLACK);
            }

            if (DrawButton(nextBtn)) shopIndex = (shopIndex + 1) % shopCars.size();
            if (DrawButton(prevBtn)) shopIndex = (shopIndex - 1 + shopCars.size()) % shopCars.size();
            if (DrawButton(backBtn)) screen = MENU;
        }

        // ================= GARAGEM =================
        else if (screen == GARAGEM) {
            DrawText("Lasanhas", 350, 30, 40, DARKGRAY);

            if (garage.empty()) {
                DrawText("Nenhum carro comprado", 330, 300, 20, GRAY);
            } else {
                Car& car = garage[garageIndex];

                DrawRectangle(330, 150, 240, 120, DARKBLUE);
                DrawText(TextFormat("%s (%d)", car.name.c_str(), car.year), 330, 290, 22, BLACK);

                DrawText(TextFormat("0-100 km/h: %.1f s", car.zeroToHundred), 330, 330, 20, DARKGRAY);
                DrawText(TextFormat("Velocidade Max: %d km/h", car.maxSpeed), 330, 360, 20, DARKGRAY);
                DrawText(TextFormat("Potencial: %d", car.cavalos), 330, 390, 20, DARKGRAY);

                if (DrawButton(nextBtn)) garageIndex = (garageIndex + 1) % garage.size();
                if (DrawButton(prevBtn)) garageIndex = (garageIndex - 1 + garage.size()) % garage.size();
            }

            if (DrawButton(backBtn)) screen = MENU;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

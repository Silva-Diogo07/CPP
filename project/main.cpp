#include <raylib.h>
#include <vector>
#include <algorithm>

#include "struct.h"
#include "screens.h"
#include "button.h"

int main() {

    // Inicialização da janela
    InitWindow(900, 600, "Mini Jogo");
    SetTargetFPS(120);

    Screen screen = MENU;
    int money = 999999;

    // Carros disponíveis na loja
    std::vector<Car> shopCars = {
        {"Supra", 1997, 100000, 1.0f, 500, 1000},
        {"Civic", 2000, 50000, 20.0f, 120, 90},
        {"Corolla", 2010, 30000, 30.0f, 90, 60}
    };

    // Garagem
    std::vector<Car> garage;
    int shopIndex = 0;
    int garageIndex = 0;

    // ---------- BOTÕES MENU ----------
    Button playBtn   = {{350, 180, 200, 60}, "JOGAR", GRAY};
    Button garageBtn = {{350, 260, 200, 60}, "GARAGEM", GRAY};
    Button shopBtn   = {{350, 340, 200, 60}, "TCAR", GRAY};

    // ---------- BOTÕES GARAGEM/LOJA ----------

    Button buyBtn   = {{350, 470, 200, 50}, "COMPRAR", GREEN};
    Button backBtn  = {{20, 540, 160, 40}, "MENU", GRAY};
    Button nextBtn  = {{780, 300, 80, 40}, ">", GRAY};
    Button prevBtn  = {{40, 300, 80, 40}, "<", GRAY};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(TextFormat("FPS: %d", GetFPS()), 20, 50, 20, RED);

        switch(screen) {
            case MENU:
                updateMenu(screen, money, playBtn, garageBtn, shopBtn);
                drawMenu(money, playBtn, garageBtn, shopBtn);
                break;

            case CONCESSIONARIA:
                updateShop(screen, money, shopCars, garage, shopIndex, buyBtn, nextBtn, prevBtn, backBtn);
                drawShop(money, shopCars, garage, shopIndex, buyBtn, nextBtn, prevBtn, backBtn);
                break;

            case GARAGEM:
                updateGarage(screen, garage, garageIndex, nextBtn, prevBtn, backBtn);
                drawGarage(garage, garageIndex, nextBtn, prevBtn, backBtn);
                break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

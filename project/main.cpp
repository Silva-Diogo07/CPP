#include <raylib.h>
#include <vector>
#include <algorithm>

#include "struct.h"
#include "screens.h"
#include "button.h"


int main(int argc, char** argv) {
    // Runtime debug flag (set via --debug)
    bool runtimeDebug = false;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--debug") runtimeDebug = true;
    }

    // Compile-time debug detection
    #ifdef DEBUG
    constexpr bool compileTimeDebug = true;
    #else
    constexpr bool compileTimeDebug = false;
    #endif

    bool debugEnabled = compileTimeDebug || runtimeDebug;

    if (debugEnabled) {
        printf("Debug enabled (compile=%d, runtime=%d)\n", (int)compileTimeDebug, (int)runtimeDebug);
    }

    InitWindow(900, 600, "Mini Jogo");
    SetTargetFPS(120);

    Screen screen = MENU;
    int money = 999999;

    std::vector<Car> shopCars = {
        {"Supra", 1997, 100000, 1.0f, 500, 1000},
        {"Civic", 2000, 50000, 20.0f, 120, 90},
        {"Corolla", 2010, 30000, 30.0f, 90, 60}
    };

    // Debug helpers: keep a copy to toggle an empty shop during runtime
    std::vector<Car> defaultShopCars = shopCars;
    bool debugEmptyShop = false;

    std::vector<Car> garage;
    int shopIndex = 0;
    int garageIndex = 0;

    // ---------- BOTÕES ----------
    Button playBtn   = {{350, 180, 200, 60}, "JOGAR", GRAY};
    Button garageBtn = {{350, 260, 200, 60}, "GARAGEM", GRAY};
    Button shopBtn   = {{350, 340, 200, 60}, "TCAR", GRAY};

    Button buyBtn   = {{350, 470, 200, 50}, "COMPRAR", GREEN};
    Button backBtn  = {{20, 540, 160, 40}, "MENU", GRAY};
    Button nextBtn  = {{780, 300, 80, 40}, ">", GRAY};
    Button prevBtn  = {{40, 300, 80, 40}, "<", GRAY};

    while (!WindowShouldClose())
    {
        DrawText(TextFormat("FPS: %d", GetFPS()), 20, 50, 20, RED);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (debugEnabled) {
            // Debug controls: E = toggle empty shop, B = auto-buy current car, I = set invalid index
            if (IsKeyPressed(KEY_E)) {
                debugEmptyShop = !debugEmptyShop;
                if (debugEmptyShop) {
                    shopCars.clear();
                } else {
                    shopCars = defaultShopCars;
                }
                shopIndex = 0;
                printf("Debug: empty shop = %d\n", debugEmptyShop);
            }
            if (IsKeyPressed(KEY_B)) {
                if (shopCars.empty()) {
                    printf("Debug: shop is empty\n");
                } else {
                    shopIndex = std::clamp(shopIndex, 0, (int)shopCars.size() - 1);
                    const Car& c = shopCars[shopIndex];
                    if (money >= c.price) {
                        money -= c.price;
                        garage.push_back(c);
                        printf("Debug: bought %s for $%d, money now %d\n", c.name.c_str(), c.price, money);
                    } else {
                        printf("Debug: not enough money to buy %s (price=%d, money=%d)\n", c.name.c_str(), c.price, money);
                    }
                }
            }
            if (IsKeyPressed(KEY_I)) {
                shopIndex = 1000;
                printf("Debug: set shopIndex to %d\n", shopIndex);
            }

            DrawText("Debug: E-toggle empty shop, B-auto-buy, I-set invalid index", 10, 70, 12, DARKGRAY);
        }

        switch(screen)
        {
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

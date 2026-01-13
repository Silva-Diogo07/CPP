#include "screens.h"
#include "button.h"

#ifndef UNIT_TEST
#include <raylib.h>
#endif

#include <vector>
#include <string>
#include <algorithm>

// ---------------------- UI STATE ----------------------
struct UIState {
    char moneyText[64] = {0};
    int lastMoney = -1;

    char carNameText[64] = {0};
    char carPriceText[64] = {0};
    int lastShopIndex = -1;
    int lastShopSize = -1;

    char garageCarNameText[64] = {0};
    int lastGarageIndex = -1;
    int lastGarageSize = -1;
};

static UIState uiState;

// ---------------------- MENU ----------------------
void updateMenu(Screen& screen, int& money,
                Button& playBtn, Button& garageBtn, Button& shopBtn)
{
#ifndef UNIT_TEST
    if (DrawButton(garageBtn)) screen = GARAGEM;
    if (DrawButton(shopBtn))   screen = CONCESSIONARIA;
#endif
}

void drawMenu(int money, const Button& playBtn, const Button& garageBtn, const Button& shopBtn)
{
#ifndef UNIT_TEST
    // Atualiza texto do dinheiro apenas se mudou
    if (money != uiState.lastMoney) {
        snprintf(uiState.moneyText, sizeof(uiState.moneyText), "Dinheiro: $%d", money);
        uiState.lastMoney = money;
    }

    DrawText("MENU PRINCIPAL", 300, 80, 40, DARKGRAY);
    DrawText(uiState.moneyText, 20, 20, 20, DARKGREEN);

    DrawButton(playBtn);
    DrawButton(garageBtn);
    DrawButton(shopBtn);
#endif
}

// ---------------------- SHOP ----------------------
void updateShopLogic(Screen& screen, int& money,
                     std::vector<Car>& shopCars, std::vector<Car>& garage,
                     int& shopIndex,
                     bool buyPressed, bool nextPressed, bool prevPressed, bool backPressed)
{
    // Protege contra vetor vazio e índices inválidos
    if (shopCars.empty()) {
        shopIndex = 0;
        if (backPressed) screen = MENU;
        return;
    }

    shopIndex = std::clamp(shopIndex, 0, (int)shopCars.size() - 1);
    const Car& car = shopCars[shopIndex];

    if (buyPressed && money >= car.price) {
        money -= car.price;
        garage.push_back(car);
    }

    if (nextPressed) shopIndex = (shopIndex + 1) % (int)shopCars.size();
    if (prevPressed) shopIndex = (shopIndex - 1 + (int)shopCars.size()) % (int)shopCars.size();
    if (backPressed) screen = MENU;
}

void updateShop(Screen& screen, int& money,
                std::vector<Car>& shopCars, std::vector<Car>& garage,
                int& shopIndex,
                const Button& buyBtn, const Button& nextBtn,
                const Button& prevBtn, const Button& backBtn)
{
#ifndef UNIT_TEST
    bool buyPressed = DrawButton(buyBtn);
    bool nextPressed = DrawButton(nextBtn);
    bool prevPressed = DrawButton(prevBtn);
    bool backPressed = DrawButton(backBtn);
    updateShopLogic(screen, money, shopCars, garage, shopIndex, buyPressed, nextPressed, prevPressed, backPressed);
#else
    // In unit tests we call updateShopLogic directly
    updateShopLogic(screen, money, shopCars, garage, shopIndex, false, false, false, false);
#endif
}

void drawShop(int money,
              const std::vector<Car>& shopCars, const std::vector<Car>& garage,
              int shopIndex,
              const Button& buyBtn, const Button& nextBtn,
              const Button& prevBtn, const Button& backBtn)
{
#ifndef UNIT_TEST
    DrawText("LASANHAS", 340, 30, 40, DARKGRAY);

    // Atualiza texto do dinheiro apenas se mudou
    if (money != uiState.lastMoney) {
        snprintf(uiState.moneyText, sizeof(uiState.moneyText), "Dinheiro: $%d", money);
        uiState.lastMoney = money;
    }
    DrawText(uiState.moneyText, 20, 20, 20, DARKGREEN);

    if (shopCars.empty()) {
        DrawText("Nenhum carro disponível", 330, 200, 20, GRAY);
        DrawButton(backBtn);
        return;
    }

    // garante índice válido e atualiza cache de textos do carro
    shopIndex = std::clamp(shopIndex, 0, (int)shopCars.size() - 1);
    const Car& car = shopCars[shopIndex];

    if (shopIndex != uiState.lastShopIndex || (int)shopCars.size() != uiState.lastShopSize) {
        snprintf(uiState.carNameText, sizeof(uiState.carNameText), "%s (%d)", car.name.c_str(), car.year);
        snprintf(uiState.carPriceText, sizeof(uiState.carPriceText), "Preço: $%d", car.price);
        uiState.lastShopIndex = shopIndex;
        uiState.lastShopSize = shopCars.size();
    }

    DrawRectangle(330, 120, 240, 120, BLUE);

    DrawText(uiState.carNameText, 330, 260, 22, BLACK);
    DrawText(uiState.carPriceText, 330, 290, 20, BLACK);

    DrawText(TextFormat("0-100 km/h: %.1f s", car.zeroToHundred), 330, 330, 20, DARKGRAY);
    DrawText(TextFormat("Velocidade Max: %d km/h", car.maxSpeed), 330, 360, 20, DARKGRAY);
    DrawText(TextFormat("Potência: %d", car.cavalos), 330, 390, 20, DARKGRAY);

    // Botão comprar
    if (money >= car.price) {
        DrawButton(buyBtn);
    } else {
        DrawRectangleRec(buyBtn.rect, DARKGRAY);
        DrawText("SEM DINHEIRO", 370, 485, 18, BLACK);
    }

    DrawButton(nextBtn);
    DrawButton(prevBtn);
    DrawButton(backBtn);
#endif
}

// ---------------------- GARAGE ----------------------
void updateGarageLogic(Screen& screen, std::vector<Car>& garage, int& garageIndex,
                         bool nextPressed, bool prevPressed, bool backPressed)
{
    if (!garage.empty()) {
        garageIndex = std::clamp(garageIndex, 0, (int)garage.size() - 1);
        if (nextPressed) garageIndex = (garageIndex + 1) % (int)garage.size();
        if (prevPressed) garageIndex = (garageIndex - 1 + (int)garage.size()) % (int)garage.size();
    }

    if (backPressed) screen = MENU;
}

void updateGarage(Screen& screen, std::vector<Car>& garage, int& garageIndex,
                  const Button& nextBtn, const Button& prevBtn, const Button& backBtn)
{
#ifndef UNIT_TEST
    bool nextPressed = DrawButton(nextBtn);
    bool prevPressed = DrawButton(prevBtn);
    bool backPressed = DrawButton(backBtn);
    updateGarageLogic(screen, garage, garageIndex, nextPressed, prevPressed, backPressed);
#else
    updateGarageLogic(screen, garage, garageIndex, false, false, false);
#endif
}

void drawGarage(const std::vector<Car>& garage, int garageIndex,
                const Button& nextBtn, const Button& prevBtn, const Button& backBtn)
{
#ifndef UNIT_TEST
    DrawText("GARAGEM", 350, 30, 40, DARKGRAY);

    if (garage.empty()) {
        DrawText("Nenhum carro comprado", 330, 300, 20, GRAY);
        DrawButton(backBtn);
        return;
    }

    garageIndex = std::clamp(garageIndex, 0, (int)garage.size() - 1);
    const Car& car = garage[garageIndex];

    if (garageIndex != uiState.lastGarageIndex || (int)garage.size() != uiState.lastGarageSize) {
        snprintf(uiState.garageCarNameText, sizeof(uiState.garageCarNameText), "%s (%d)", car.name.c_str(), car.year);
        uiState.lastGarageIndex = garageIndex;
        uiState.lastGarageSize = garage.size();
    }

    DrawRectangle(330, 150, 240, 120, DARKBLUE);
    DrawText(uiState.garageCarNameText, 330, 290, 22, BLACK);

    DrawText(TextFormat("0-100 km/h: %.1f s", car.zeroToHundred), 330, 330, 20, DARKGRAY);
    DrawText(TextFormat("Velocidade Max: %d km/h", car.maxSpeed), 330, 360, 20, DARKGRAY);
    DrawText(TextFormat("Potência: %d", car.cavalos), 330, 390, 20, DARKGRAY);

    DrawButton(nextBtn);
    DrawButton(prevBtn);
    DrawButton(backBtn);
#endif
}

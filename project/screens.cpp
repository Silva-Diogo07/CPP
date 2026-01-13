#include "screens.h"
#include "button.h"

#include <raylib.h>
#include <vector>
#include <string>

using namespace std;

// ---------------------- CACHE DE TEXTOS ----------------------
static char moneyText[64];
static int lastMoney = -1;

static char carNameText[64];
static char carPriceText[64];
static int lastShopIndex = -1;

static char garageCarNameText[64];
static int lastGarageIndex = -1;

// ---------------------- MENU ----------------------
void updateMenu(Screen& screen, int& money,
                Button& playBtn, Button& garageBtn, Button& shopBtn)
{
    if (DrawButton(garageBtn)) screen = GARAGEM;
    if (DrawButton(shopBtn))   screen = CONCESSIONARIA;
}

void drawMenu(int money,
              const Button& playBtn, const Button& garageBtn, const Button& shopBtn)
{
    // Atualiza texto do dinheiro apenas se mudou
    if (money != lastMoney) {
        snprintf(moneyText, sizeof(moneyText), "Dinheiro: $%d", money);
        lastMoney = money;
    }

    DrawText("MENU PRINCIPAL", 300, 80, 40, DARKGRAY);
    DrawText(moneyText, 20, 20, 20, DARKGREEN);

    DrawButton(playBtn);
    DrawButton(garageBtn);
    DrawButton(shopBtn);
}

// ---------------------- SHOP ----------------------
void updateShop(Screen& screen, int& money,
                vector<Car>& shopCars, vector<Car>& garage,
                int& shopIndex,
                const Button& buyBtn, const Button& nextBtn,
                const Button& prevBtn, const Button& backBtn)
{
    Car& car = shopCars[shopIndex];

    if (money >= car.price) {
        if (DrawButton(buyBtn)) {
            money -= car.price;
            garage.push_back(car);
        }
    }

    if (DrawButton(nextBtn)) shopIndex = (shopIndex + 1) % shopCars.size();
    if (DrawButton(prevBtn)) shopIndex = (shopIndex - 1 + shopCars.size()) % shopCars.size();
    if (DrawButton(backBtn)) screen = MENU;
}

void drawShop(int money,
              const vector<Car>& shopCars, const vector<Car>& garage,
              int shopIndex,
              const Button& buyBtn, const Button& nextBtn,
              const Button& prevBtn, const Button& backBtn)
{
    Car& car = const_cast<Car&>(shopCars[shopIndex]); // apenas para acessar dados

    // Atualiza cache de textos do carro
    if (shopIndex != lastShopIndex) {
        snprintf(carNameText, sizeof(carNameText), "%s (%d)", car.name.c_str(), car.year);
        snprintf(carPriceText, sizeof(carPriceText), "Preço: $%d", car.price);
        lastShopIndex = shopIndex;
    }

    DrawText("LASANHAS", 340, 30, 40, DARKGRAY);
    DrawText(moneyText, 20, 20, 20, DARKGREEN);

    DrawRectangle(330, 120, 240, 120, BLUE);

    DrawText(carNameText, 330, 260, 22, BLACK);
    DrawText(carPriceText, 330, 290, 20, BLACK);

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
}

// ---------------------- GARAGE ----------------------
void updateGarage(Screen& screen, vector<Car>& garage, int& garageIndex,
                  const Button& nextBtn, const Button& prevBtn, const Button& backBtn)
{
    if (!garage.empty()) {
        if (DrawButton(nextBtn)) garageIndex = (garageIndex + 1) % garage.size();
        if (DrawButton(prevBtn)) garageIndex = (garageIndex - 1 + garage.size()) % garage.size();
    }

    if (DrawButton(backBtn)) screen = MENU;
}

void drawGarage(const vector<Car>& garage, int garageIndex,
                const Button& nextBtn, const Button& prevBtn, const Button& backBtn)
{
    DrawText("GARAGEM", 350, 30, 40, DARKGRAY);

    if (garage.empty()) {
        DrawText("Nenhum carro comprado", 330, 300, 20, GRAY);
        return;
    }

    Car& car = const_cast<Car&>(garage[garageIndex]);

    // Atualiza cache do nome
    if (garageIndex != lastGarageIndex) {
        snprintf(garageCarNameText, sizeof(garageCarNameText), "%s (%d)", car.name.c_str(), car.year);
        lastGarageIndex = garageIndex;
    }

    DrawRectangle(330, 150, 240, 120, DARKBLUE);
    DrawText(garageCarNameText, 330, 290, 22, BLACK);

    DrawText(TextFormat("0-100 km/h: %.1f s", car.zeroToHundred), 330, 330, 20, DARKGRAY);
    DrawText(TextFormat("Velocidade Max: %d km/h", car.maxSpeed), 330, 360, 20, DARKGRAY);
    DrawText(TextFormat("Potência: %d", car.cavalos), 330, 390, 20, DARKGRAY);

    DrawButton(nextBtn);
    DrawButton(prevBtn);
    DrawButton(backBtn);
}

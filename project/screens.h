#ifndef SCREENS_H
#define SCREENS_H

#include <vector>
#include "struct.h"   // Car, Button
#include "button.h"   // Button se separado

enum Screen { MENU, CONCESSIONARIA, GARAGEM };

// ---------------- MENU ----------------
void updateMenu(Screen& screen, int& money,
                Button& playBtn, Button& garageBtn, Button& shopBtn);

void drawMenu(int money,
              const Button& playBtn, const Button& garageBtn, const Button& shopBtn);

// ---------------- SHOP ----------------
void updateShop(Screen& screen, int& money,
                std::vector<Car>& shopCars, std::vector<Car>& garage,
                int& shopIndex,
                const Button& buyBtn, const Button& nextBtn,
                const Button& prevBtn, const Button& backBtn);

// Pure logic variant for unit testing (buttons represented as booleans)
void updateShopLogic(Screen& screen, int& money,
                     std::vector<Car>& shopCars, std::vector<Car>& garage,
                     int& shopIndex,
                     bool buyPressed, bool nextPressed, bool prevPressed, bool backPressed);

void drawShop(int money,
              const std::vector<Car>& shopCars, const std::vector<Car>& garage,
              int shopIndex,
              const Button& buyBtn, const Button& nextBtn,
              const Button& prevBtn, const Button& backBtn);

// ---------------- GARAGE ----------------
void updateGarage(Screen& screen, std::vector<Car>& garage, int& garageIndex,
                  const Button& nextBtn, const Button& prevBtn, const Button& backBtn);

// Pure logic variant for unit testing (buttons represented as booleans)
void updateGarageLogic(Screen& screen, std::vector<Car>& garage, int& garageIndex,
                       bool nextPressed, bool prevPressed, bool backPressed);

void drawGarage(const std::vector<Car>& garage, int garageIndex,
                const Button& nextBtn, const Button& prevBtn, const Button& backBtn);

#endif
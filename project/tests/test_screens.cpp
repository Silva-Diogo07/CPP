#include <iostream>
#include <vector>
#include <string>

#include "screens.h"
#include "struct.h"

int failures = 0;

void expect(bool cond, const char* msg) {
    if (!cond) {
        std::cerr << "FAIL: " << msg << "\n";
        ++failures;
    } else {
        std::cout << "PASS: " << msg << "\n";
    }
}

void test_empty_shop() {
    Screen screen = CONCESSIONARIA;
    int money = 1000;
    std::vector<Car> shopCars;
    std::vector<Car> garage;
    int shopIndex = 5;

    updateShopLogic(screen, money, shopCars, garage, shopIndex, true, false, false, false);

    expect(shopIndex == 0, "shopIndex resets to 0 on empty shop");
    expect(garage.empty(), "garage remains empty when buying from empty shop");
    expect(money == 1000, "money unchanged when buying from empty shop");
}

void test_buy() {
    Screen screen = CONCESSIONARIA;
    int money = 200000;
    std::vector<Car> shopCars = { {"Test", 2000, 100000, 1.0f, 100, 100} };
    std::vector<Car> garage;
    int shopIndex = 0;

    updateShopLogic(screen, money, shopCars, garage, shopIndex, true, false, false, false);

    expect(money == 100000, "money decreased after buy");
    expect(garage.size() == 1, "garage has one car after buy");
    expect(garage[0].name == "Test", "bought correct car");
}

void test_index_clamp_and_wrap() {
    Screen screen = CONCESSIONARIA;
    int money = 0;
    std::vector<Car> shopCars = {
        {"A", 2000, 100, 1.0f, 10, 10},
        {"B", 2001, 200, 1.0f, 20, 20},
        {"C", 2002, 300, 1.0f, 30, 30}
    };
    std::vector<Car> garage;
    int shopIndex = 100; // invalid

    updateShopLogic(screen, money, shopCars, garage, shopIndex, false, false, false, false);
    expect(shopIndex == 2, "shopIndex clamped to size-1 when out of range");

    updateShopLogic(screen, money, shopCars, garage, shopIndex, false, true, false, false); // next
    expect(shopIndex == 0, "next wraps to 0");

    updateShopLogic(screen, money, shopCars, garage, shopIndex, false, false, true, false); // prev
    expect(shopIndex == 2, "prev wraps to last");
}

void test_garage_navigation() {
    Screen screen = GARAGEM;
    std::vector<Car> garage = {
        {"G1", 2000, 100, 1.0f, 10, 10},
        {"G2", 2001, 200, 1.0f, 20, 20}
    };
    int garageIndex = 5;

    updateGarageLogic(screen, garage, garageIndex, true, false, false);
    // initial clamp should set to 1, then next makes it (1+1)%2 == 0
    expect(garageIndex == 0, "garage next wraps correctly with initial invalid index");

    updateGarageLogic(screen, garage, garageIndex, false, true, false);
    expect(garageIndex == 1, "garage prev wraps correctly");
}

int main() {
    test_empty_shop();
    test_buy();
    test_index_clamp_and_wrap();
    test_garage_navigation();

    if (failures == 0) {
        std::cout << "ALL TESTS PASSED\n";
        return 0;
    } else {
        std::cerr << failures << " test(s) failed\n";
        return 1;
    }
}

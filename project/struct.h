#ifndef STRUCTS_H
#define STRUCTS_H

#include <raylib.h>
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

#endif // STRUCTS_H



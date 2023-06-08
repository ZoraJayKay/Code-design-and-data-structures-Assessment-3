#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raylib.h"

#include <iostream>


int main()
{
    int windowWidth = 1080;
    int windowHeight = 720;

    InitWindow(windowWidth, windowHeight, "Zora Jane Kerr : Code design and data structures (Assessment 2 - Binary Tree) (AIE, 2023[student year 1])");

    while (!WindowShouldClose()) {
        // run test program that show the tree works
    }

    CloseWindow();

    return 0;
}

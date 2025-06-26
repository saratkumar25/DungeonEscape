#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon() {
    grid = {
        {{EMPTY}, {TRAP}, {EMPTY}, {WALL}, {EXIT}},
        {{WALL}, {EMPTY}, {KEY}, {DOOR}, {WALL}},
        {{EMPTY}, {EMPTY}, {WALL}, {TRAP}, {EMPTY}},
        {{EMPTY}, {WALL}, {EMPTY}, {EMPTY}, {EMPTY}},
        {{EMPTY}, {EMPTY}, {EMPTY}, {TRAP}, {EMPTY}}
    };
}

void Dungeon::print(int playerX, int playerY) {
    std::cout << "\nDungeon Map:\n";
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (i == playerX && j == playerY) std::cout << "@ ";
            else {
                switch (grid[i][j].type) {
                    case WALL: std::cout << "# "; break;
                    case TRAP: std::cout << "T "; break;
                    case KEY: std::cout << "K "; break;
                    case DOOR: std::cout << "D "; break;
                    case EXIT: std::cout << "E "; break;
                    default: std::cout << ". "; break;
                }
            }
        }
        std::cout << "\n";
    }
}

bool Dungeon::isWall(int x, int y) {
    return grid[x][y].type == WALL;
}

bool Dungeon::isExit(int x, int y) {
    return grid[x][y].type == EXIT;
}

Cell& Dungeon::getCell(int x, int y) {
    return grid[x][y];
}

bool Dungeon::isWithinBounds(int x, int y) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
}

int Dungeon::getStartX() { return 0; }
int Dungeon::getStartY() { return 0; }

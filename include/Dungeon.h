#ifndef DUNGEON_H
#define DUNGEON_H
#include <vector>
#include <string>

enum TileType { EMPTY, WALL, TRAP, KEY, DOOR, EXIT };

struct Cell {
    TileType type;
};

class Dungeon {
private:
    std::vector<std::vector<Cell>> grid;
public:
    Dungeon();
    void print(int playerX, int playerY);
    bool isWall(int x, int y);
    bool isExit(int x, int y);
    Cell& getCell(int x, int y);
    bool isWithinBounds(int x, int y);
    int getStartX();
    int getStartY();
};
#endif
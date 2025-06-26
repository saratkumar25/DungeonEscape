#ifndef GAME_H
#define GAME_H
#include "Dungeon.h"
#include "Player.h"
#include <stack>

class Game {
private:
    Dungeon dungeon;
    Player player;
    std::stack<std::pair<int, int>> moveHistory;
public:
    Game();
    void start();
    void movePlayer(char dir);
    bool isValidMove(int x, int y);
    void processCell(Cell& cell);
};

#endif
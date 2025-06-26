#include "Game.h"
#include <iostream>

Game::Game() : dungeon(), player(dungeon.getStartX(), dungeon.getStartY()) {}

void Game::start() {
    char input;
    while (true) {
        dungeon.print(player.getX(), player.getY());
        std::cout << "Move (WASD): ";
        std::cin >> input;
        movePlayer(toupper(input));
        if (dungeon.isExit(player.getX(), player.getY())) {
            std::cout << "\n🎉 You escaped the dungeon!\n";
            break;
        }
        if (player.getHP() <= 0) {
            std::cout << "\n💀 You died in the dungeon!\n";
            break;
        }
    }
}

void Game::movePlayer(char dir) {
    int dx = 0, dy = 0;
    if (dir == 'W') dx = -1;
    else if (dir == 'S') dx = 1;
    else if (dir == 'A') dy = -1;
    else if (dir == 'D') dy = 1;
    int newX = player.getX() + dx;
    int newY = player.getY() + dy;
    if (isValidMove(newX, newY)) {
        moveHistory.push({player.getX(), player.getY()});
        player.setPosition(newX, newY);
        processCell(dungeon.getCell(newX, newY));
    }
}

bool Game::isValidMove(int x, int y) {
    return dungeon.isWithinBounds(x, y) && !dungeon.isWall(x, y);
}

void Game::processCell(Cell& cell) {
    if (cell.type == TRAP) {
        std::cout << "\n⚠️  Stepped on a trap! -1 HP\n";
        player.takeDamage(1);
    } else if (cell.type == KEY) {
        std::cout << "\n🗝️  You picked up a key!\n";
        player.addKey("gold");
        cell.type = EMPTY;
    } else if (cell.type == DOOR) {
        if (player.hasKey("gold")) {
            std::cout << "\n🚪 Opened the door with a key!\n";
            cell.type = EMPTY;
        } else {
            std::cout << "\n🔒 Door is locked. Find a key!\n";
            player.setPosition(moveHistory.top().first, moveHistory.top().second);
            moveHistory.pop();
        }
    }
}
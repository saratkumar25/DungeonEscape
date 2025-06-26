#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_set>
#include <string>

class Player {
private:
    int x, y;
    int hp;
    std::unordered_set<std::string> keys;
public:
    Player(int startX, int startY);
    int getX();
    int getY();
    int getHP();
    void setPosition(int x, int y);
    void takeDamage(int d);
    void addKey(const std::string& key);
    bool hasKey(const std::string& key);
};
#endif
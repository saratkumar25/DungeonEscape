#include "Player.h"

Player::Player(int startX, int startY) : x(startX), y(startY), hp(3) {}

int Player::getX() { return x; }
int Player::getY() { return y; }
int Player::getHP() { return hp; }

void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Player::takeDamage(int d) {
    hp -= d;
}

void Player::addKey(const std::string& key) {
    keys.insert(key);
}

bool Player::hasKey(const std::string& key) {
    return keys.count(key) > 0;
}

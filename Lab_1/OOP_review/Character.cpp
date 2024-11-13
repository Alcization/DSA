#include <iostream>
using namespace std;


class Character {

protected:
    int hp;
    int x;
    int y;
public:
    Character::Character() {
        this->hp = 0;
        this->x = 0;
        this->y = 0;
    }

    Character::Character(int hp, int x, int y) {
        this->hp = hp;
        this->x = x;
        this->y = y;
    }

    int Character::getHp() {
        return hp;
    }

    void Character::setHp(int hp) {
        this->hp = hp;
    }

    int Character::getX() {
        return x;
    }

    void Character::setX(int x) {
        this->x = x;
    }

    int Character::getY() {
        return y;
    }

    void Character::setY(int y) {
        this->y = y;
    }

    int Character::getManhattanDistTo(Character* other) {
        int length = other->x - this->x;
        int height = other->y - this->y;
        length = abs(length);
        height = abs(height);
        double result;
        result = length + height;
        return result;
    }
};

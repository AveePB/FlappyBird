#include "logic.hpp"

int main() {
    mz::Game* flappyBird = mz::Game::getInstance();
    if (!flappyBird->run()) return -1;
    return 0;
}
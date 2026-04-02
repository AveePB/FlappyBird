#ifndef GAME_HPP
#define GAME_HPP

#include "sprites.hpp"

namespace flappy_bird {
 
    class Game {
    private:
        static void takeScreenshot(sf::RenderWindow& window);
        bool bird_boost;

    public:
        Game();
        ~Game();

        void handleEvent(sf::RenderWindow& window, const sf::Event& event);
        void update();
        void render(sf::RenderWindow& window);
    };
}

#endif
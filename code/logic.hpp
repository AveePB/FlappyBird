#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <memory>
#include "sprites.hpp"

namespace mz {

    class Game {
    private:
        // Fundamental elements
        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<sf::Clock> clock;

        // Textures
        sf::Texture bg_tex, grass_tex, bottom_tube_tex, top_tube_tex, player_tex;

        // Sprites
        std::unique_ptr<mz::Bird> player;
        std::unique_ptr<sf::Sprite> bg, bottom_tube, top_tube;
        std::unique_ptr<mz::Grass> grass;

        bool loadTextures();
        bool createSprites();
        bool init();
        void drawAndDisplay();

        Game() {}

    public:
        Game(const Game& g) = delete;
        bool run();

        static Game* getInstance();
    };
}

#endif
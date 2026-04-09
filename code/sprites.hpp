#ifndef SPRITES_HPP
#define SPRITES_HPP

// Libraries
#include <SFML/Graphics.hpp>
#include "consts.hpp"

namespace mz {

    class Bird : public sf::Sprite {

    public:
        Bird(const sf::Texture& t);
        void applyFallEffect();
        void applyRiseEffect();
    };

    class Grass : public sf::Sprite {
    private:
        float width;
    public:
        Grass(const sf::Texture& t);
        void move();
    };

    class Tubes : public sf::Sprite {

    };
}

#endif

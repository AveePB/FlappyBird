#ifndef SPRITES_HPP
#define SPRITES_HPP

// Libraries
#include <SFML/Graphics.hpp>
#include "consts.hpp"

namespace mz {

    class Bird : public sf::Sprite {
    public:
        enum State { RESTING, FALLING, RISING };
    private:
        mz::Bird::State currState;
        float boost, fall_linear_velocity;

    public:
        Bird(const sf::Texture& t);
        void applyFallEffect(const float& dt);
        bool applyRiseEffect(const float& dt);
        void setState(const State& newState);
        void setBoost(const float& newBoost);
        State getState();
    };

    class Grass : public sf::Sprite {
    private:
        float width;

    public:
        Grass(const sf::Texture& t);
        void move(const float& dt);
    };
}

#endif

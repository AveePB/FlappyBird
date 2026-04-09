#include "sprites.hpp"
#include <iostream>

mz::Bird::Bird(const sf::Texture& t) : sf::Sprite(t) {
    // Set position and rotation point
    this->setOrigin(sf::Vector2f(t.getSize()) / 2.0f);
    this->setPosition({ mz::WINDOW_WIDTH / 4.0f, mz::WINDOW_HEIGHT / 2.0f });
}

void mz::Bird::applyFallEffect() {
    // Update bird position and rotation
    float rot = this->getRotation().asDegrees() + 5.0f;
    rot = (rot > 360.f) ? rot - 360.0f : rot;
    rot = (rot < 315.0f && rot > 90.0f) ? 90.0f : rot;


    sf::Vector2f pos = this->getPosition();
    pos.y += 10.0f;

    this->setPosition(pos);
    this->setRotation(sf::degrees(rot));
}

void mz::Bird::applyRiseEffect() {
    // Update bird position and rotation
    sf::Vector2f pos = this->getPosition();
    pos.y -= 175.0f;

    this->setPosition(pos);
    this->setRotation(sf::degrees(315.0f));
}

mz::Grass::Grass(const sf::Texture& t) : sf::Sprite(t) {
    this->width = t.getSize().x * mz::TEXTURE_SCALE;
    this->setPosition({ 0.0f, (float)WINDOW_HEIGHT - t.getSize().y * mz::TEXTURE_SCALE });
}

void mz::Grass::move() {
    // Move grass to the left and when it is out of window, reset position
    sf::Vector2f pos = this->getPosition();
    pos.x -= 10.0f;
    pos.x = (pos.x <= mz::WINDOW_WIDTH - this->width) ? 0.0f : pos.x;
    this->setPosition(pos);
}

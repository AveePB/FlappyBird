#include "sprites.hpp"
#include <iostream>

mz::Bird::Bird(const sf::Texture& t) : sf::Sprite(t), currState(mz::Bird::State::RESTING), boost(0.0f), fall_linear_velocity(0.0f) {
    // Set position and rotation point
    this->setOrigin(sf::Vector2f(t.getSize()) / 2.0f);
    this->setPosition({ mz::WINDOW_WIDTH / 4.0f, mz::WINDOW_HEIGHT / 2.0f });
}

void mz::Bird::applyFallEffect(const float& dt) {
    // Update bird position and rotation
    float rot = this->getRotation().asDegrees() + mz::BIRD_FALL_ANGULAR_VELOCITY * dt;
    rot = (rot > 360.0f) ? rot - 360.0f : rot;
    rot = (rot > 90.0f && rot < 315.0f) ? 90.0f : rot;

    sf::Vector2f pos = this->getPosition();
    this->fall_linear_velocity += mz::BIRD_FALL_LINEAR_ACCELERATION * mz::BIRD_FALL_MAX_LINEAR_VELOCITY;
    this->fall_linear_velocity = std::max(this->fall_linear_velocity, BIRD_FALL_MAX_LINEAR_VELOCITY);
    pos.y += this->fall_linear_velocity * dt;

    this->setPosition(pos);
    this->setRotation(sf::degrees(rot));
}

bool mz::Bird::applyRiseEffect(const float& dt) {
    // Update bird position and rotation
    this->fall_linear_velocity = 0.0f;
    sf::Vector2f pos = this->getPosition();
    pos.y -= mz::BIRD_RISE_LINEAR_VELOCITY * dt;
    this->boost -= mz::BIRD_RISE_LINEAR_VELOCITY * dt;

    this->setPosition(pos);
    this->setRotation(sf::degrees(315.0f));
    return this->boost <= 0;
}

void mz::Bird::setState(const mz::Bird::State& newState) {
    this->currState = newState;
}

mz::Bird::State mz::Bird::getState() {
    return this->currState;
}

void mz::Bird::setBoost(const float& newBoost) {
    this->boost = newBoost;
}

mz::Grass::Grass(const sf::Texture& t) : sf::Sprite(t) {
    this->width = t.getSize().x * mz::TEXTURE_SCALE;
    this->setPosition({ 0.0f, (float)WINDOW_HEIGHT - t.getSize().y * mz::TEXTURE_SCALE });
}

void mz::Grass::move(const float& dt) {
    // Move grass to the left and when it is out of window, reset position
    sf::Vector2f pos = this->getPosition();
    pos.x -= mz::GRASS_VELOCITY * dt;
    pos.x = (pos.x <= mz::WINDOW_WIDTH - this->width) ? 0.0f : pos.x;
    this->setPosition(pos);
}

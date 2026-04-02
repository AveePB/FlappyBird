#include "game.hpp"
#include <iostream>

void flappy_bird::Game::takeScreenshot(sf::RenderWindow& window) {}

flappy_bird::Game::Game() {
    bird_boost = false;
}

flappy_bird::Game::~Game() {}

void flappy_bird::Game::handleEvent(sf::RenderWindow& window, const sf::Event& event) {
    
    if (event.is<sf::Event::Closed>()) { // Close game window
        window.close();
    }
    else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) { // Handle pressed keys

        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) window.close(); // Close window on ESC
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Z) takeScreenshot(window); // Take screenshot on Z
        else if (keyPressed->scancode == sf::Keyboard::Scancode::Up) bird_boost = true;
    }

    else if (const auto* keyReleassed = event.getIf<sf::Event::KeyReleased>()) { // Handle released keys
        if (keyReleassed->scancode == sf::Keyboard::Scancode::Up) this->bird_boost = false; // Unboost bird
    }

}

void flappy_bird::Game::update() {
    std::cout << this->bird_boost << "\n";
}

void flappy_bird::Game::render(sf::RenderWindow& window) {}

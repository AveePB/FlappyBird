#include <iostream>
#include "logic.hpp"
#include "consts.hpp"

bool mz::Game::loadTextures() {
    if (!this->bg_tex.loadFromFile(mz::BG_TEX_PATH)) {
        std::cerr << "[Error]: Could not load texture: \"" << mz::BG_TEX_PATH << "\"\n";
        return false;
    }

    if (!this->grass_tex.loadFromFile(mz::GRASS_TEX_PATH)) {
        std::cerr << "[Error]: Could not load texture: \"" << mz::GRASS_TEX_PATH << "\"\n";
        return false;
    }

    if (!this->bottom_tube_tex.loadFromFile(mz::BOTTOM_TUBE_TEX_PATH)) {
        std::cerr << "[Error]: Could not load texture: \"" << mz::BOTTOM_TUBE_TEX_PATH << "\"\n";
        return false;
    }

    if (!this->top_tube_tex.loadFromFile(mz::TOP_TUBE_TEX_PATH)) {
        std::cerr << "[Error]: Could not load texture: \"" << mz::TOP_TUBE_TEX_PATH << "\"\n";
        return false;
    }

    if (!this->player_tex.loadFromFile(mz::PLAYER_TEX_PATH)) {
        std::cerr << "[Error]: Could not load texture: \"" << mz::PLAYER_TEX_PATH << "\"\n";
        return false;
    }

    return true;
}

bool mz::Game::createSprites() {
    try {
        this->bg = std::make_unique<sf::Sprite>(this->bg_tex);
        this->bg->setScale({ mz::TEXTURE_SCALE, mz::TEXTURE_SCALE });

        this->grass = std::make_unique<mz::Grass>(this->grass_tex);
        this->grass->setScale({ mz::TEXTURE_SCALE, mz::TEXTURE_SCALE });

        this->bottom_tube = std::make_unique<sf::Sprite>(this->bottom_tube_tex);
        this->bottom_tube->setScale({ mz::TEXTURE_SCALE, mz::TEXTURE_SCALE });

        this->top_tube = std::make_unique<sf::Sprite>(this->top_tube_tex);
        this->top_tube->setScale({ mz::TEXTURE_SCALE, mz::TEXTURE_SCALE });

        this->player = std::make_unique<mz::Bird>(this->player_tex);
        this->player->setScale({ mz::TEXTURE_SCALE, mz::TEXTURE_SCALE });
    }
    catch (...) {
        return false;
    }
    return true;
}

bool mz::Game::init() {
    bool loaded_tex = loadTextures();
    if (!loaded_tex) return false;

    bool created_sprites = createSprites();
    if (!created_sprites) return false;

    this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ mz::WINDOW_WIDTH, mz::WINDOW_HEIGHT }), mz::WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(mz::FPS);

    sf::Image icon;
    if (icon.loadFromFile(mz::PLAYER_TEX_PATH)) this->window->setIcon(icon);

    return true;
}

void mz::Game::handleEvents() {
    bool is_jump = false;

    while (const std::optional event = this->window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) // Close button pressed
            this->window->close();

        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) // Some key pressed
            switch (keyPressed->scancode) {

            case sf::Keyboard::Scancode::Escape: // Close window
                this->window->close();
                break;

            case sf::Keyboard::Scancode::Space: // Jump
                this->player->applyRiseEffect();
                is_jump = true;
                break;
            }
    }

    this->grass->move();
    if (!is_jump) this->player->applyFallEffect();
}

void mz::Game::drawAndDisplay() {
    this->window->draw(*this->bg);
    this->window->draw(*this->grass);
    this->window->draw(*this->player);
    this->window->display();
}

mz::Game* mz::Game::getInstance() {
    static Game singleton;
    return &singleton;
}

bool mz::Game::run() {
    if (!this->init()) return false;

    while (this->window->isOpen()) {
        this->handleEvents();
        this->drawAndDisplay();
    }

    return true;
}
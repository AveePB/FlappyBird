#include <iostream>
#include <chrono>
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

    this->clock = std::make_unique<sf::Clock>();

    sf::Image icon;
    if (icon.loadFromFile(mz::PLAYER_TEX_PATH)) this->window->setIcon(icon);

    return true;
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
    this->player->setState(mz::Bird::FALLING);
    bool wasSpaceReleased = true;

    while (this->window->isOpen()) {
        // Get time
        sf::Time dt = this->clock->restart();
        float deltaTime = dt.asMilliseconds();

        // Handle events
        while (const std::optional event = this->window->pollEvent()) {

            // X button pressed
            if (event->is<sf::Event::Closed>())
                this->window->close();

            // Some key event happened
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                switch (keyPressed->scancode) {
                
                    case sf::Keyboard::Scancode::Escape:
                        this->window->close();
                        break;

                    case sf::Keyboard::Scancode::Space:
                        if (wasSpaceReleased) {
                            this->player->setState(mz::Bird::State::RISING);
                            this->player->setBoost(mz::BOOST_PX);
                            wasSpaceReleased = false;
                        }
                        break;
                }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
                if (keyPressed->scancode == sf::Keyboard::Scancode::Space) wasSpaceReleased = true;
        }

        // Update logic
        this->grass->move(deltaTime);

        // Update bird logic
        switch (this->player->getState()) {

            case mz::Bird::State::FALLING:
                this->player->applyFallEffect(deltaTime);
                break;
            
            case mz::Bird::State::RISING:
                if (this->player->applyRiseEffect(deltaTime)) 
                    this->player->setState(mz::Bird::State::FALLING);
                break;

            case mz::Bird::State::RESTING:
                break;
        }
        
        this->drawAndDisplay();
    }
    return true;
}
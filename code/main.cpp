#include "game.hpp"

// Constants
const std::string WINDOW_TITLE = "Flappy Bird";
const int WINDOW_WIDTH = 864;
const int WINDOW_HEIGHT = 1536;

int main() {
    // Create the window
    sf::RenderWindow my_window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    flappy_bird::Game my_game;

    // Run the program as long as the window is open
    while (my_window.isOpen()) {
        
        // Handle game events
        while (const std::optional event = my_window.pollEvent())
            my_game.handleEvent(my_window, *event);

        // Update game logic and render scene
        my_game.update();
        my_game.render(my_window);
    }

    return 0;
}

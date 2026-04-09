#ifndef CONSTS_HPP
#define CONSTS_HPP

namespace mz {
    // Window settings
    const unsigned int TEXTURE_SCALE = 5;
    const unsigned int WINDOW_WIDTH = TEXTURE_SCALE * 144;
    const unsigned int WINDOW_HEIGHT = TEXTURE_SCALE * 256;
    const std::string WINDOW_TITLE = "Flappy Bird";
    const unsigned int FPS = 30;

    // Texture paths
    const std::string PLAYER_TEX_PATH = "./assets/sprites/bird-up.png";
    const std::string GRASS_TEX_PATH = "./assets/env/grass.png";
    const std::string BOTTOM_TUBE_TEX_PATH = "./assets/sprites/bottom-tube.png";
    const std::string TOP_TUBE_TEX_PATH = "./assets/sprites/top-tube.png";
    const std::string BG_TEX_PATH = "./assets/env/background.png";
}

#endif
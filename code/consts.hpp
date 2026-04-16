#ifndef CONSTS_HPP
#define CONSTS_HPP

namespace mz {
    // Window settings
    const unsigned int TEXTURE_SCALE = 5;
    const unsigned int WINDOW_WIDTH = TEXTURE_SCALE * 144;
    const unsigned int WINDOW_HEIGHT = TEXTURE_SCALE * 256;
    const std::string WINDOW_TITLE = "Flappy Bird";
    const unsigned int FPS = 90;

    // Texture paths
    const std::string PLAYER_TEX_PATH = "./assets/sprites/bird-up.png";
    const std::string GRASS_TEX_PATH = "./assets/env/grass.png";
    const std::string BOTTOM_TUBE_TEX_PATH = "./assets/sprites/bottom-tube.png";
    const std::string TOP_TUBE_TEX_PATH = "./assets/sprites/top-tube.png";
    const std::string BG_TEX_PATH = "./assets/env/background.png";

    // Bird 
    const float BIRD_FALL_ANGULAR_VELOCITY = 0.150f;
    const float BIRD_FALL_MAX_LINEAR_VELOCITY = 0.250f;
    const float BIRD_FALL_LINEAR_ACCELERATION = 0.100f;

    const float BIRD_RISE_ANGULAR_VELOCITY = 0.200f;
    const float BIRD_RISE_LINEAR_VELOCITY = 1.000f;
    const float BOOST_PX = 100.0f;

    // Background
    const float GRASS_VELOCITY = 0.150f;
}

#endif
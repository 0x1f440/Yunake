#ifndef __GAME_HPP__
#define __GAME_HPP__
#include "GameMap.hpp"
#include "Snake.hpp"

class Game {
private:
    Snake *snake;
    GameMap *map;
    void renderScene();
public:
    Game();
    Game(int mapHeight, int mapWidth);
    ~Game();
    void run();
};

#endif
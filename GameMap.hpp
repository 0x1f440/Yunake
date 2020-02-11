#ifndef __GAMEMAP_HPP__
#define __GAMEMAP_HPP__

class GameMap {
private:
    int height;
    int width;
    int** map;
public:
    GameMap(int height, int width);
    ~GameMap();
    int getHeight();
    int getWidth();
    const int** getMap();
    void placeFoodOnMap(int y, int x);
    bool isCoordInRange(int y, int x);
};

#endif
﻿#include "GameMap.hpp"
#include <memory.h>

GameMap::GameMap(int height, int width) {
    this->height = height;
    this->width = width;
    this->map = new int*[height];
    for(int i=0;i<height;i++) {
        this->map[i] = new int[width];
        memset(this->map[i], 0, sizeof(this->map[i]));
    }
}

GameMap::~GameMap() {

}

int GameMap::getHeight() {
    return height;
}

int GameMap::getWidth() {
    return width;
}

const int** GameMap::getMap() {
    return (const int**)map;
}

void GameMap::placeFoodOnMap(int y, int x) {
	this->map[y][x] = 1;
}

bool GameMap::isCoordInRange(int y, int x) {
    return y >= 0 && y < this->height && x >= 0 && x < this->width;
}
#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include "Game.hpp"
#include "Snake.hpp"
#include "GameMap.hpp"
using namespace std;

Game::Game() {
    this->snake = new Snake(24, 40);
    this->map = new GameMap(24, 40);
}

Game::Game(int mapHeight, int mapWidth) {
    this->snake = new Snake(mapHeight, mapWidth);
    this->map = new GameMap(mapHeight, mapWidth);
}

Game::~Game() {
    delete this->snake;
    delete this->map;
}

int sumFrame;

void Game::renderScene() {
    int height = this->map->getHeight();
    int width = this->map->getWidth();
	string _screen;

    for (int i = -1; i <= height; i++)
    {
        for(int j = -1; j <= width; j++)
        {
			if (!this->map->isCoordInRange(i, j)) {
				_screen.append("■");
			}
			else if (this->snake->isJointExistsAtCoord(i, j)) {
				_screen.append("□");
			}
			else if (this->map->getMap()[i][j] == 1) {
				_screen.append("★");
			}
			else {
				_screen.append("　");
			}
        }
		_screen.push_back('\n');
    }
	printf("%s\n%d", _screen.c_str(),sumFrame++);
}


void Game::run() {
    bool gameOver = false;
	int height = this->map->getHeight();
	int width = this->map->getWidth();

	srand(time(NULL));
	this->map->placeFoodOnMap(height, width);

    while(!gameOver) {
        system("cls");
        this->renderScene();

		Sleep(100);
        gameOver = !this->snake->move(height, width);
    }
    cout << "\nGAME OVER!! YOUR FINAL SCORE WAS: " << this->snake->getSnakeLength() << endl;
}
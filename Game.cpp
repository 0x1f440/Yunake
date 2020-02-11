#include <iostream>
#include <string>
#include <windows.h>
#include "Game.hpp"
#include "Snake.hpp"
#include "GameMap.hpp"
using namespace std;

Game::Game() {
    this->snake = new Snake();
    this->map = new GameMap(24, 40);
}

Game::Game(int mapHeight, int mapWidth) {
    this->snake = new Snake();
    this->map = new GameMap(mapHeight, mapWidth);
}

Game::~Game() {
    delete this->snake;
    delete this->map;
}

int sumFrame;

void Game::renderScene() {
    // GameMap과 Snake를 참조하여 게임 씬을 그려보자!
    // Requirements
    // 1. 테두리를 그려주세요
    // 2. 뱀은 ㅁ 그거 있지 그거
    // 3. 먹이는 카와이하게 별모야응로
    // 4. 빈 칸은 ㄱ 한자 1 하면 나오는 전각 그림
    // 힌트?
    // 아래 코드는 돌아가지 않습니다 아시조
    // for(i=0;i<height;i++) {
    //     for(j=0;j<width;j++) {
    //         if (map[i][j] == 먹이) cout << '카와이한 별'
    //         else if (snake.includeJointAt(x,y)) cout << '네모';
    //         else cout << '그 빈 칸'
    //     }
    // }
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
    while(!gameOver) {
        system("cls");
        this->renderScene();
		Sleep(100);
        gameOver = !this->snake->move();
    }
    cout << "GAME OVER!! YOUR FINAL SCORE WAS: " << this->snake->getSnakeLength() << endl;
}
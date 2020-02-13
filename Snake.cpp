#include <iostream>
#include "Snake.hpp"

Snake::Snake(int y, int x) {
	SnakeJoint sj = SnakeJoint(y / 2, x / 2);

	this->snakeBody.push_back(sj);
	this->direction = DIR_RIGHT;
}

void Snake::changeDirection(int keycode) {
	switch (keycode)
	{
		case 72:    // key up
			this->direction = DIR_UP;
			break;

		case 80:    // key down
			this->direction = DIR_DOWN;
			break;

		case 77:    // key right
			this->direction = DIR_RIGHT;
			break;

		case 75:    // key left
			this->direction = DIR_LEFT;
			break;
	}
}

int Snake::getSnakeLength() {
	return this->snakeBody.size();
}

void Snake::importSnakeJoint(int y, int x) {
	//이게 뭐하는 함수지
	//사과를 먹는 함수라고 하네요

	SnakeJoint sj = SnakeJoint(y, x);
	this->snakeBody.push_front(sj);
}

bool Snake::move(int mapHeight, int mapWidth) {

	// https://stackoverflow.com/questions/17771406/c-initial-value-of-reference-to-non-const-must-be-an-lvalue
	// initial value of reference to non-const must be an lvalue 
	// for (auto const &sb = this->snakeBody.rbegin(); sb!= this->snakeBody.end(); sb++)

	//값 변경 안 할 거니까 const
	const auto d = this->direction;
	const auto sj = this->snakeBody.front();

	switch (d)
	{
		case DIR_UP:
			if (isJointExistsAtCoord(sj.y-1, sj.x)) return false;
			if (sj.y-1 > mapHeight) return false;
			
			this->snakeBody.push_front(SnakeJoint(sj.y-1, sj.x));
			break;

		case DIR_DOWN:

			if (isJointExistsAtCoord(sj.y+1, sj.x)) return false;
			if (sj.y + 1 < 0) return false;

			this->snakeBody.push_front(SnakeJoint(sj.y+1, sj.x));
			break;

		case DIR_LEFT:
			if (isJointExistsAtCoord(sj.y, sj.x-1)) return false;
			if (sj.x - 1 < 0) return false;

			this->snakeBody.push_front(SnakeJoint(sj.y, sj.x-1));
			break;

		case DIR_RIGHT:
			if (isJointExistsAtCoord(sj.y, sj.x+1)) return false;
			if (sj.x + 1 > mapWidth) return false;

			this->snakeBody.push_front(SnakeJoint(sj.y, sj.x+1));
			break;
	}
	this->snakeBody.pop_back();
	
    return true;
}

bool Snake::isJointExistsAtCoord(int y, int x) {
	// 머하러 값을 복사하냐 싶어서 & 썻는데 이래도 되나?
	for (const SnakeJoint &sj : this->snakeBody) {
		if (sj.x == x && sj.y == y) {
			std::cout << "충돌 ㅎㅎ!\n";
			return true;
		}
	}
	return false;
}

SnakeJoint::SnakeJoint(int y, int x)
{
	this->x = x;
	this->y = y;
}

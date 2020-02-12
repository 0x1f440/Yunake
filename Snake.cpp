#include "Snake.hpp"

Snake::Snake(int y, int x) {
    // 그 뱀은... 길이 1로 (y,x)에서 태어났다...
    // 첫 시작점을 어떻게 할 지 생각해보세용

	// map의 사이즈를 어떻게 불러올 것인가 ???
	// 아래 네 줄을 한 번에 할 수 있는 방법??

	SnakeJoint sj = SnakeJoint();
	
	sj.y = y / 2;
	sj.x = x / 2;

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

}

bool Snake::move(int mapHeight, int mapWidth) {
	auto d = this->direction;

	for (auto& sj : this->snakeBody) {
		switch (d)
		{
			case DIR_UP:
				if (isJointExistsAtCoord(sj.y+1, sj.x)) return false;
				if (sj.y + 1 > mapHeight) return false;

				--sj.y;
				break;

			case DIR_DOWN:

				if (isJointExistsAtCoord(sj.y-1, sj.x)) return false;
				if (sj.y - 1 < 0) return false;

				++sj.y;

				break;

			case DIR_LEFT:
				if (isJointExistsAtCoord(sj.y, sj.x-1)) return false;
				if (sj.x - 1 < 0) return false;

				--sj.x;

				break;

			case DIR_RIGHT:
				if (isJointExistsAtCoord(sj.y, sj.x+1)) return false;
				if (sj.x + 1 > mapWidth) return false;

				++sj.x;
				break;
		}
	}
    return true;
}

bool Snake::isJointExistsAtCoord(int y, int x) {
	// 머하러 값을 복사하냐 싶어서 & 썻는데 이래도 되나?
	for (const SnakeJoint &sj : this->snakeBody) {
		if (sj.x == x && sj.y == y)
			return true;
	}
	return false;
}

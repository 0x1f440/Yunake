#include "Snake.hpp"

Snake::Snake() {
    // 그 뱀은... 길이 1로 (y,x)에서 태어났다...
    // 첫 시작점을 어떻게 할 지 생각해보세용
}

int Snake::getSnakeLength() {
	return this->snakeBody.size();
}

void Snake::importSnakeJoint(int y, int x) {
	//이게 뭐하는 함수지 
}

bool Snake::move() {
    return true;
}

bool Snake::isJointExistsAtCoord(int y, int x) {
    return false;
}

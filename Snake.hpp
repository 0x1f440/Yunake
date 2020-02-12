#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <list>
using namespace std;

enum Direction {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
};

struct SnakeJoint {
    int x;
    int y;
};

class Snake {
private:
    list <SnakeJoint> snakeBody;
    Direction direction;
public:
    Snake(int y, int x);
    int getSnakeLength();
	void changeDirection(int keycode);
    void importSnakeJoint(int y, int x);
	bool move(int y, int x); // tick이 흐르고 snake가 움직일 때 움직일 수 있는지 체크: 두 가지 관점에서. 하나는 벽꿍 하나는 몸꿍. 움직일 수 있으면 true, 아니면 false
    bool isJointExistsAtCoord(int y, int x); // 바보같이 짜도 됩니다!!!! list를 전부 뒤지면서 (x,y)에 뱀관절이 있는지 확인해보세요!!!!
};
#endif
// Yunake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "Game.hpp"

int main()
{
	Game *game = new Game();
	game->run();
}

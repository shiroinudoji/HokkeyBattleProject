#pragma once
#include "Player.h"
#include "Pack.h"
class Player1 : public Player
{
public:
	using Player::Player;

	void update();

	void barrier();

	double brockLevel(Pack* pack);

	int brockX(Pack* pack);

	void playerDraw();

	void move();
};



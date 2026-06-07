#pragma once
#include <Siv3D.hpp>
class Player
{
public:
	s3d::Vec2 Pos;
	s3d::Vec2 Vel;
	int HP;
	int barriercheck;
	int barrierEndTime;
	int barrierReroadTime;
	Circle playerCircle;
	Circle barrierCircle;
	const Audio parry;
	Player(s3d::Vec2 Pos_);

	int getHP();

	virtual void update();

	virtual void move();




	void playerDraw();
};


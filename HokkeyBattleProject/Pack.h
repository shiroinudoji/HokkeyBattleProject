#pragma once
#include "Player.h"
class Pack
{
public:
	s3d::Vec2 Pos;
	s3d::Vec2 Vel;
	s3d::Vec2 preVel;
	double Level;
	int LevelVel;
	Circle packBaseCircle;
	Circle packCircle;
	Circle packSubCircle;
	int counter;
	int crashcheck;
	const Audio weak;
	const Audio powerUp;
	int lastTouch;

	Pack(s3d::Vec2 Pos_);

	void update();

	void VelChanger();

	void run();

	void wall();

	void reflect(s3d::Vec2 playerPos);

	void packDraw();

	int crash(Player player, int playerType);

	bool crashR(Player player);
	int  battle(int HP);

	int damage();
};


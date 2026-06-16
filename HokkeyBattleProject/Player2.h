#pragma once
#include "Player.h"
#include "Pack.h"
class Player2 :public Player
{
public:
	using Player::Player;
	Vec2 pack;
	Vec2 target;
	Vec2 packVel;
	double Level;
	int moveTimer;
	int UporDown;
	int barrierSkill;
	int barrierLimiter;
	int underLimit;
	int  UpDownKey;
	double secondCounter;
	bool firsttouch;
	bool barrierSign;
	Player2(s3d::Vec2 Pos_);
	void update();

	void getPackPos(double x, double y);

	void getPackLevel(double packLevel);

	void getVel(double x, double y);

	void barrier();

	double brockLevel(Pack* pack);

	int brockX(Pack* pack);

	int brockY(Pack* pack);

	void playerDraw();

	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();
	

	void moveSelect();

	void Limitbreak();

	void chase();

	void move()override;

	void crash(Pack* pack);

	void HPChanger(double);
};


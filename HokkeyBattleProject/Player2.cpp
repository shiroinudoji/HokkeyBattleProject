#include "stdafx.h"
#include "Player2.h"

Player2::Player2(s3d::Vec2 Pos_)
	:Player{Pos_},
	pack{0,0},
	   target{0,0},
	packVel{0,0},
	Level{1},
	moveTimer{ 0 },
	UporDown{ 0 },
	barrierSkill{ 0 },
	barrierLimiter{ 2 },
	underLimit{ -2 },
	UpDownKey{ 0 },
	firsttouch{ true },
	barrierSign{ false }
{
}
void Player2::update() {
	move();
	barrier();
	moveSelect();
}

void Player2::getPackPos(double x, double y) {
	pack.x = x;
	pack.y = y;
}

void Player2::getPackLevel(double packLevel) {
	Level = packLevel;
}

void Player2::getVel(double x, double y) {
	packVel.x = x;
	packVel.y = y;
}

void Player2::barrier() {
	barrierCircle = { Pos, 55 };
	if (barrierSign && barriercheck == 0) {
		barriercheck = 1;
	}
	if (barriercheck > 0 && barriercheck < barrierEndTime) {
		barrierCircle.draw(Palette::Purple);
		barriercheck++;
	}
	else if (barriercheck >= barrierEndTime && barriercheck < barrierReroadTime) {
		barriercheck++;
	}
	else if (barriercheck >= barrierReroadTime) {
		barriercheck = 0;
	}
}
void Player2::playerDraw(){
		playerCircle = { Pos, 35 };
		playerCircle.draw(Palette::Blue);
}


void Player2::moveLeft() {
	if (470 > Pos.x) {

	}
	else {
		Pos.x -= 500 * Scene::DeltaTime();
	}
}

void Player2::moveRight() {
	if (765 < Pos.x) {

	}
	else {
		Pos.x += 500 * Scene::DeltaTime();
	}
}
void Player2::moveUp() {
	if (105 > Pos.y) {

	}
	else {
		Pos.y -= 500 * Scene::DeltaTime();
	}
}

void Player2::moveDown() {
	if (495 < Pos.y) {

	}
	else {
		Pos.y += 500 * Scene::DeltaTime();
	}
}

void Player2::moveSelect() {
	if (moveTimer < 30) {
		moveTimer++;
	}
	if (moveTimer >= 30) {
		UporDown = Random(0, 1);
		barrierSkill = Random(underLimit, barrierLimiter);
		moveTimer = 0;
	}
}

void Player2::Limitbreak() {
	barrierLimiter++;
	underLimit++;
}

void Player2::chase() {
	if (Level == 0.0 && firsttouch) {

		if (UpDownKey >= 0 && UpDownKey < 30) {
			moveUp();
			UpDownKey++;
		}
		else {
			moveDown();
			UpDownKey++;
			if (UpDownKey > 60) {
				UpDownKey = 0;
			}
		}

	}
	else {
		firsttouch = false;
		if ((Level > -2.5 && pack.x > Pos.x)) {
			if (pack.y > Pos.y) {
				moveDown();
			}
			else if (pack.y < Pos.y) {
				moveUp();
			}
			else {

			}
			if (UporDown == 0) {
				moveRight();
			}
			else if (UporDown == 1) {
				moveLeft();
			}
		}
		else {
			if (pack.x > 400) {
				if (pack.y > Pos.y) {
					moveUp();
				}
				else if (pack.y < Pos.y) {
					moveDown();
				}
				else {

				}
				if (UporDown == 0) {
					moveRight();

				}
				else if (UporDown == 1) {
					moveLeft();
				}
			}
			else {
				if (pack.y > Pos.y) {
					moveDown();
				}
				else if (pack.y < Pos.y) {
					moveUp();
				}
				else {

				}
				if (UporDown == 0) {
					moveRight();
				}
				else if (UporDown == 1) {
					moveLeft();
				}
			}
		}
	}
	if (sqrt(pow((Pos.x - pack.x), 2) + pow((Pos.y - pack.y), 2)) < 87 + barrierSkill && Level > 0) {
		barrierSign = true;
	}
	else {
		barrierSign = false;
	}
}

void Player2::move() {
	chase();
}

int Player2::brockX(Pack* pack)
{
	if (barrierCircle.intersects(pack->packCircle)) {
		if (barriercheck > 0 && barriercheck < barrierEndTime) {
			if (pack->Level > 0.0) {
				return -pack->Vel.x;
			}
			else {
				return pack->Vel.x;
			}
		}
		else {
			return pack->Vel.x;
		}
	}
	else {
		return pack->Vel.x;
	}
}

int Player2::brockY(Pack* pack)
{
	if (barrierCircle.intersects(pack->packCircle)) {
		if (barriercheck > 0 && barriercheck < barrierEndTime) {
			if (pack->Level > 0.0) {
				return -pack->Vel.y;
			}
			else {
				return pack->Vel.y;
			}
		}
		else {
			return pack->Vel.y;
		}
	}
	else {
		return pack->Vel.y;
	}
}

double Player2::brockLevel(Pack* pack)
{
	if (barrierCircle.intersects(pack->packCircle)) {
		if (barriercheck > 0 && barriercheck < barrierEndTime) {
			if (pack->Level > 0.0) {
				parry.play();
				return -pack->Level;
			}
			else {
				return pack->Level;
			}
		}
		else {
			return pack->Level;
		}
	}
	else {
		return pack->Level;
	}

}
void  Player2::crash(Pack* pack) {
	if (playerCircle.intersects(pack->packCircle)) {
		if (pack->Pos.x < 35 || pack->Pos.x > 765 || pack->Pos.y < 105 || pack->Pos.y > 495)
			Pos = (Pos - pack->Pos).setLength(70) + pack->Pos;
	}
}

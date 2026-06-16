#include "stdafx.h"
#include "Player1.h"




void Player1::update() {
	move();
	barrier();
}

void Player1::barrier() {
	barrierCircle = { Pos, 55 };
	if (KeyEnter.down() && barriercheck == 0) {
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

void Player1::playerDraw() {
	playerCircle = { Pos, 35 };
	playerCircle.draw(Palette::Red);
}

void Player1::move() {
	if (KeyA.pressed()) {
		if (35 > Pos.x) {

		}
		else {
			Pos.x -= 500 * Scene::DeltaTime();
		}
	}

	if (KeyD.pressed()) {
		if (330 < Pos.x) {

		}
		else {
			Pos.x += 500 * Scene::DeltaTime();
		}
	}

	if (KeyW.pressed())
	{
		if (105 > Pos.y) {

		}
		else {
			Pos.y -= 500 * Scene::DeltaTime();
		}
	}

	if (KeyS.pressed())
	{
		if (495 < Pos.y) {

		}
		else {
			Pos.y += 500 * Scene::DeltaTime();
		}
	}
}
double Player1::brockLevel(Pack* pack)
{
	if (barrierCircle.intersects(pack->packCircle)) {
		if (barriercheck > 0 && barriercheck < barrierEndTime) {
			if (pack->Level < 0.0) {
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

int Player1::brockX(Pack* pack)
{
	if (barrierCircle.intersects(pack->packCircle)) {
		if (barriercheck > 0 && barriercheck < barrierEndTime) {
			if (pack->Level < 0.0) {
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


int Player1::brockY(Pack* pack)
{
	if (barrierCircle.intersects(pack->packCircle)) {
		if (barriercheck > 0 && barriercheck < barrierEndTime) {
			if (pack->Level < 0.0) {
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

void  Player1::crash(Pack* pack) {
	if (playerCircle.intersects(pack->packCircle)) {
		if (pack->Pos.x < 35 || pack->Pos.x > 765 || pack->Pos.y < 105 || pack->Pos.y > 495) {
			Pos = (Pos - pack->Pos).setLength(70) + pack->Pos;
		}
	}
}

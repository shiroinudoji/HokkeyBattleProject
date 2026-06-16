#include "stdafx.h"
#include "Player.h"
#include "Pack.h"


Player::Player(s3d::Vec2 Pos_)
	: Pos{ Pos_ },
	HP{300},
	barriercheck{0},
	barrierEndTime{12},
	barrierReroadTime{30},
	Vel{0,0},
	playerCircle{ Pos, 35 },
	barrierCircle{ Pos, 55 },
	weak{ U"打撃1.mp3" },
	parry{ U"剣で打ち合う4.mp3" }
{}

int Player::getHP() {
	return HP;
}

void Player::update() {

}

void Player::move() {

}


void Player::playerDraw() {

}







#include "stdafx.h"
#include "Pack.h"

Pack::Pack(s3d::Vec2 Pos_)
	: Pos{ Pos_ },
	Vel{0,0},
	preVel{0,0},
	Level{ 0.0 },
	LevelVel{ 75 },
	packBaseCircle{ Pos, 35 },
	packCircle{ Pos, 35 },
	packSubCircle{ Pos, 17 },
	counter{ 1 },
	crashcheck{ 1 },
    powerUp{ U"決定ボタンを押す49.mp3" },
	lastTouch{ 0 }
{}

void Pack::update() {
	VelChanger();
	run();
	wall();
	preVel = Vel;
}

void Pack::VelChanger() {
	if (Level == 0.0) {
		LevelVel = 75;
	}
	else if ((Level > 0.0 && Level <= 1.0) || (Level < 0.0 && Level >= -1.0)) {
		LevelVel = 75;
	}
	else if ((Level > 1.0 && Level <= 2.0) || (Level < -1.0 && Level >= -2.0)) {
		LevelVel = 100;
	}
	else if ((Level > 2.0 && Level <= 3.5) || (Level < -2.0 && Level >= -3.5)) {
		LevelVel = 125;
	}
	else {
		LevelVel = 75;
	}

}

void Pack::VectorChanger(Vec2 Vector) {
	Vel.x = Vector.x;
}

void Pack::run() {
	
	Pos.x += LevelVel * Vel.x * Scene::DeltaTime();
	Pos.y += LevelVel * Vel.y * Scene::DeltaTime();
}

void Pack::wall() {
	if (counter == 0) {
		counter++;
	}
	if (counter == 1) {
		counter = 0;
		if (Pos.x < 35) {
			Vel.x = Abs(Vel.x);
			if (Level < 0.0) {
				Level += 0.5;
			}
		}
		if (Pos.x > 765) {
			Vel.x = -Abs(Vel.x);
			if (Level > 0.0) {
				Level -= 0.5;
			}
		}
		if (Pos.y < 105) {
			Vel.y = Abs(Vel.y);
			if (Level < 0.0 && Pos.x <= 400) {
				Level += 0.5;
			}
			if (Level > 0.0 && Pos.x >= 400) {
				Level -= 0.5;
			}
		}
		if (Pos.y > 495) {
			Vel.y = -Abs(Vel.y);
			if (Level > 0.0 && Pos.x >= 400) {
				Level -= 0.5;
			}
			if (Level < 0.0 && Pos.x <= 400) {
				Level += 0.5;
			}
		}
	}
}

void Pack::reflect(Vec2 playerPos) {
	if (Pos.x > 35 && Pos.x < 765 && Pos.y > 105 && Pos.y < 495) {
		if (Pos.distanceFrom(playerPos) < 65) {
			Pos = (Pos - playerPos).setLength(70) + playerPos;
		}
	}
	Vel.x = (Pos.x - playerPos.x) / sqrt(70);
	Vel.y = (Pos.y - playerPos.y) / sqrt(70);
}

void Pack::packDraw() {
	packBaseCircle = { Pos, 35 };
	packCircle = { Pos, 35 };
	packSubCircle = { Pos, 17 };
	packBaseCircle.draw();
	if (Level > 0.0) {
		if (Level <= 1.0) {
			packCircle.draw(Palette::Yellow);

		}
		else if (Level <= 2.0) {
			packCircle.draw(Palette::Orange);
		}
		else if (Level >= 2.5) {
			packCircle.draw(Palette::Red);
		}
	}
	else if (Level < 0.0) {
		if (Level >= -1.0) {
			packCircle.draw(Palette::Skyblue);
		}
		else if (Level >= -2.0) {
			packCircle.draw(ColorF(0, 250, 255, 0.5));
		}
		else if (Level <= -2.5) {
			packCircle.draw(Palette::Blue);
		}
	}
	else {
		packCircle.draw();
	}
	packSubCircle.draw();
}

int Pack::crash(Player player, int playerType) {
	if (packCircle.intersects(player.playerCircle)) {
		reflect(player.Pos);
		lastTouch = playerType;
		return battle(player.HP);
	}
	else {
		if (preVel == Vel) {
			crashcheck = 1;
		}
		return player.HP;
	}
}



int  Pack::battle(int HP) {
	int temp;
	if (crashcheck == 1) {

		crashcheck = 0;

		if (Level == 0.0 && lastTouch == 1) {
			Level = 1.0;
			powerUp.play();
			return HP;
		}
		else if (Level < 0.0 && lastTouch == 1) {
			temp = (HP - damage());
			Level = 1.0;
			return temp;
		}
		else if (lastTouch == 1) {
			if (Level < 3.0) {
				powerUp.play();
				Level += 1.0;
			}
			return HP;
		}

		if (Level == 0.0 && lastTouch == 2) {
			Level = -1.0;
			powerUp.play();
			return HP;
		}
		else if (Level > 0.0 && lastTouch == 2) {
			temp = (HP - damage());
			Level = -1.0;
			return temp;
		}
		else if (lastTouch == 2) {
			if (Level > -3.0) {
				powerUp.play();
				Level -= 1.0;
			}
			return HP;
		}

	}
	else {
		crashcheck = 0;

		return HP;
	}

}

int Pack::damage() {
	if (Level == 0.0) {
		return 0;
	}
	else if ((Level > 0.0 && Level <= 1.0) || (Level < 0.0 && Level >= -1.0)) {
		return 25;
	}
	else if ((Level > 1.0 && Level <= 2.0) || (Level < -1.0 && Level >= -2.0)) {
		return 50;
	}
	else if ((Level > 2.0 && Level <= 3.5) || (Level < -2.0 && Level >= -3.5)) {
		return 75;
	}
	else {
		return 0;
	}
}

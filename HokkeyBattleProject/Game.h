#pragma once
#include "Screen.h"
#include "Player1.h"
#include "Player2.h"
#include "Pack.h"
class Game : public App::Scene {
public:
	Player1 player1;
	Player2 player2;
	Pack pack;
	Rect Menu0;
	Rect Menu1;
	Rect subHP1;
	Rect subHP2;
	Rect HP1;
	Rect HP2;
	Rect line;
	Rect result;
	Font player1Label;
	Font player2Label;
	Font player1Win;
	Font player2Win;
	Font Level;
	Font Tips;
	Font Exit;
	Font Retry;
	Font LimitBreak;
	Vec2 Vel;
	int move = 0;
	double HPtmp[2];
	const Audio decided;
	int state = 0;
	Game(const InitData& init);
	void update() override;
};



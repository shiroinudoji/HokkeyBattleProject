#include "stdafx.h"
#include "Game.h"
Game::Game(const InitData& init)
	:IScene{ init },
     player1{Vec2{ 100, 300 }},
	player2{ Vec2{ 700, 300 }},
	pack{ Vec2{ 200, 300 }},
	Menu0{ Rect(0, 0, 800, 70) },
	Menu1{ Rect(0, 530, 800, 70) },
	subHP1{ Rect(50, 25, 300, 20) },
	subHP2{ Rect(450, 555, 300, 20) },
	HP1{ Rect(50, 25, player1.HP, 20) },
	HP2{ Rect(450, 555, player2.HP, 20) },
	player1Label{ FontMethod::MSDF, 48 },
    player2Label{ FontMethod::MSDF, 48 },
	player1Win{ FontMethod::MSDF, 48 },
	player2Win{ FontMethod::MSDF, 48 },
	Level{ FontMethod::MSDF, 48 },
	Tips{ FontMethod::MSDF, 48 },
	Exit{ FontMethod::MSDF, 48 },
	Retry{ FontMethod::MSDF, 48 },
	LimitBreak{ FontMethod::MSDF, 48 },
	decided{ U"拍子木2.mp3" },
	Vel{ Vec2{0,0} },
	state{ 0 }
{
	
}


void Game::update()
{
	
	Scene::SetBackground(Palette::Green);
	player2.getPackPos(pack.Pos.x, pack.Pos.y);
	player2.getPackLevel(pack.Level);
	player2.getVel(pack.Vel.x, pack.Vel.y);
	Rect HP1(50, 25, player1.HP, 20);
	Rect HP2(450, 555, player2.HP, 20);



	player1.HP = pack.crash(player1, 1);
	player2.HP = pack.crash(player2, 2);

	Vel.x = player1.brockX(&pack);
	//Vel.y = player1.brockY(&pack);
	pack.VectorChanger(Vel);
	Vel.x = player2.brockX(&pack);
	//Vel.y = player2.brockY(&pack);
	pack.VectorChanger(Vel);
	pack.Level = player1.brockLevel(&pack);
	pack.Level = player2.brockLevel(&pack);
	player1.crash(&pack);

	if (state == 0) {
		player1.update();
		player2.update();
		pack.update();
		if (player2.HP <= 0) {
			decided.play();
			state = 1;
		}
		if (player1.HP <= 0) {
			decided.play();
			state = 2;
		}
	}


	pack.packDraw();
	player1.playerDraw();
	player2.playerDraw();
	Menu0.draw();
	Menu1.draw();
	subHP1.draw(Palette::Red);
	subHP2.draw(Palette::Red);
	player1Label(U"player1"_fmt()).draw(25, Vec2{ 370, 20 }, Palette::Black);
	player2Label(U"CPU Lv{}"_fmt(player2.barrierLimiter - 1)).draw(25, Vec2{ 330, 550 }, Palette::Black);
	Tips(U"WASDで移動!Enterでバリアで反射ができる!"_fmt()).draw(15, Vec2{ 0 ,0 }, Palette::Black);


	if (player1.HP > 0) {
		HP1.draw(Palette::Yellowgreen);
	}
	if (player2.HP > 0) {
		HP2.draw(Palette::Yellowgreen);
	}


	if (state == 1) {
		if (player2.HP <= 0) {
			player1Win(U"You Win!!"_fmt()).draw(50, Vec2{ 200, 275 }, Palette::Pink);
			Exit(U"Escapeで終了"_fmt()).draw(25, Vec2{ 200, 325 }, Palette::Pink);
			Retry(U"RでRetry"_fmt()).draw(25, Vec2{ 200, 350 }, Palette::Pink);
			LimitBreak(U"Lで難易度アップしてもう一回"_fmt()).draw(25, Vec2{ 200, 375 }, Palette::Pink);
		}
		if (KeyR.down()) {
			player1.HP = 300;
			player2.HP = 300;
			pack.Level = 0;
			player1.Pos.x = 100;
			player1.Pos.y = 300;
			player2.Pos.x = 700;
			player2.Pos.y = 300;
			player2.firsttouch = true;
			pack.Pos.x = 200;
			pack.Pos.y = 300;
			pack.Vel.x = 0;
			pack.Vel.y = 0;
			state = 0;
		}
		if (KeyL.down()) {
			player1.HP = 300;
			player2.HP = 300;
			pack.Level = 0;
			player1.Pos.x = 100;
			player1.Pos.y = 300;
			player2.Pos.x = 700;
			player2.Pos.y = 300;
			player2.firsttouch = true;
			pack.Pos.x = 200;
			pack.Pos.y = 300;
			pack.Vel.x = 0;
			pack.Vel.y = 0;
			player2.Limitbreak();
			state = 0;
		}
	}

	if (state == 2) {
		if (player1.HP <= 0) {
			player2Win(U"You Lose..."_fmt()).draw(50, Vec2{ 200, 275 }, Palette::Purple);
			Exit(U"Escapeで終了"_fmt()).draw(25, Vec2{ 200, 325 }, Palette::Purple);
			Retry(U"RでRetry"_fmt()).draw(25, Vec2{ 200, 350 }, Palette::Purple);
		}
		if (KeyR.down()) {
			player1.HP = 300;
			player2.HP = 300;
			pack.Level = 0;
			player1.Pos.x = 100;
			player1.Pos.y = 300;
			player2.Pos.x = 700;
			player2.Pos.y = 300;
			player2.firsttouch = true;
			pack.Pos.x = 200;
			pack.Pos.y = 300;
			pack.Vel.x = 0;
			pack.Vel.y = 0;
			state = 0;
		}
	}
}

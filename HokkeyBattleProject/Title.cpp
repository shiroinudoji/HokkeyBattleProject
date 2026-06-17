#include "stdafx.h"
#include "Title.h"

Title::Title(const InitData& init)
	:IScene{ init },
	Menu0{ Rect{300, 325, 200, 50} },
	Menu1{ Rect{325, 395, 150, 50} }
{

}


void Title::update()
{
	Scene::SetBackground(Palette::Green);
	if ( MouseL.down() && Menu0.intersects(Cursor::Pos()) ) {
		changeScene(U"Game", 1s);
	}
	menuDraw();
}

void Title::menuDraw() {
	Menu0.draw();
	Menu1.draw();
}

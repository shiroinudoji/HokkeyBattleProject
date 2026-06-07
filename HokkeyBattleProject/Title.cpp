#include "stdafx.h"
#include "Title.h"

Title::Title(const InitData& init)
	:IScene{ init }
{

}
void Title::update()
{
	Scene::SetBackground(Palette::Green);
	if (KeySpace.down()) {
		changeScene(U"Select", 1s);
	}
}

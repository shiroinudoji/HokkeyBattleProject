#include "stdafx.h"
#include "Select.h"

Select::Select(const InitData& init)
	:IScene{ init }
{

}

void Select::update()
{
	Scene::SetBackground(Palette::Green);
	
	if (KeySpace.down()) {
		changeScene(U"Game", 1s);
	}
}

#pragma once
#include "Screen.h"


class Title : public App::Scene {
public:
	Title(const InitData& init);
	Rect Menu0;
	Rect Menu1;
	Font start;
	int Select;
	

	void update() override;

	void menuDraw();
};



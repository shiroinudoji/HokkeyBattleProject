#pragma once
#include "Screen.h"


class Title : public App::Scene {
public:
	Title(const InitData& init);
	
	void update() override;
};

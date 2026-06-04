#include "stdafx.h"
struct StageData
{
	int playerCharacterNumber = 0;
	int enemyCharacterNumber = 0;
};

using App = SceneManager<String, StageData>;

class Title : public App::Scene {
public:

};

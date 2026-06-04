#include "stdafx.h"
struct StageData
{
	int playerCharacterNumber = 0;
	int enemyCharacterNumber = 0;
};

using App = SceneManager<String, StageData>;

class Game : public App::Scene {
public:

};

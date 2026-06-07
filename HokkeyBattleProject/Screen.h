#pragma once
	struct StageData
	{
		int state = 0;
		int playerCharacterNumber = 0;
		int enemyCharacterNumber = 0;
	};

	using App = SceneManager<String, StageData>;



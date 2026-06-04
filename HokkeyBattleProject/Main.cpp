# include <Siv3D.hpp> // Siv3D v0.6.14
# include "Title.h"
# include "Select.h"
# include "Game.h"
# include "Result.h"

struct StageData
{
	int playerCharacterNumber = 0;
	int enemyCharacterNumber = 0;
};

using App = SceneManager<String, StageData>;



void Main()
{
	App manager;

	manager.add<Title>(U"Title");

	manager.add<Select>(U"Select");

	manager.add<Game>(U"Game");

	manager.add<Result>(U"Result");



	while (System::Update())
	{

		if (not manager.update())
		{
			break;
		}
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//

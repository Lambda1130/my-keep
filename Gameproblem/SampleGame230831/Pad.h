#pragma once

//パッドの状態を取得する
namespace Pad
{
	//パッドの更新処理　1フレームに一回行う
	void Update();

	//押されているかを取得
	bool IsPress(int Key);
	//押された瞬間を取得
	bool IsTrigger(int Key);
	//話した瞬間を取得
	bool IsRelase(int Key);
}
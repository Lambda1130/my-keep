#include "DxLib.h"
#include"SceneMain.h"

namespace
{
	constexpr int kRectNum = 32;
}
/*
//矩形同士の当たり判定
bool IsCollision(const Rect& rect0, const Rect& rect1)
{
	rect0.GetRight();  //プレイヤーの左端のX座標
	rect1.GetRight();  //対象の右端のX座標

	//rect0の完全に左にいる場合は当たっていない
	if (rect0.GetLeft() > rect1.GetRight())
	{
		return false;
	}
	//rect0の完全に下にいる場合当たっていない
	if (rect0.GetBottom() < rect1.GetTop())
	{
		return false;
	}
	//rect0の完全に右にいる場合当たっていない
	if (rect0.GetRight() < rect1.GetLeft())
	{
		return false;
	}
	//rect0の完全に上にいる場合当たっていない
	if (rect0.GetTop() > rect1.GetBottom())
	{
		return false;
	}
	//完全に当たっていないパターンを取り除いて
	//残ったやつは当たっている
	return true;
}
*/

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SceneMain sceneMain;

	sceneMain.Init();

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		sceneMain.Update();

		//描画
		sceneMain.Draw();

		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	sceneMain.End();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
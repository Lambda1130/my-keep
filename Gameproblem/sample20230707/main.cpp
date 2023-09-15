#include "DxLib.h"
#include"Game.h"
#include"Enemy.h"
#include"Player.h"
#include<cassert>

#include"SceneManager.h"

namespace
{
	
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	//画面のサイズ変更
	SetGraphMode(Game::kSreenWidth, Game::kSreenHeigt, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//シーン
	SceneManager scene;
	scene.Init();

	while (ProcessMessage() != -1)
	{
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		//実行中のシーンの更新、描画を行う
		scene.Update();

		//シーンの切り替え行う
		scene.Draw();

		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}

	}

	
	scene.End();

		// 画面が切り替わるのを待つ
		ScreenFlip();


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}







/*
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	//画面のサイズ変更
	SetGraphMode(Game::kSreenWidth,Game::kSreenHeigt, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//ゲーム準備
	int sceneNo = 0;   //現在のシーンを変数で持つ
	                   //0:Title 1:Main
	                   //本来はenum等でやるべき
	SceneTitle sceneTitle;
	SceneMain sceneMain;

	switch (sceneNo)
	{
	case 0:
		sceneTitle.Init();
		break;
	case 1:
		sceneMain.Init();
	default:
		assert(false);
		break;
	}

	sceneTitle.Init();
	
	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		
				
		switch (sceneNo)
		{
		case 0:
			sceneTitle.Update();
			sceneTitle.Draw();
			if (sceneTitle.isEnd())
			{
				//タイトルの終了
				sceneTitle.End();

				//次のシーン
				sceneNo = 1;
				sceneMain.Init();
			}
			break;
		case 1:
			sceneMain.Update();
			sceneMain.Draw();
			break;
		default:
			assert(false);
			break;
		}

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

	sceneTitle.End();
	

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
*/




#include "DxLib.h"
#include "player.h"
#include  "enemy.h"
#include <cmath>

namespace
{
	//敵の数
	constexpr int kEnemyNum = 3;
	//敵の位置情報
	constexpr int kEnemyIntervalX = 160;
}

//プレイヤーと敵があったているか判定する
//クラス、構造体を引数として渡す場合はポインタ、参照渡し推奨
//値渡しだとデータのコピーに時間がかかるため
bool isCollision(Player& player, Enemy& enemy)
{
	//判定に必要なプレイヤー
	float playerPosX = (float)player.getPosX();
	float playerPosY = (float)player.getPosY();
	float playerRadius = (float)player.getRadius();

	//敵の情報
	float enemyPosX = (float)enemy.getPosX();
	float enemyPosY = (float)enemy.getPosY();
	float enemyRadius = (float)enemy.getRadius();

	float dx = playerPosX - enemyPosX;
	float dy = playerPosY - enemyPosY;
	float dist = sqrtf(dx * dx + dy * dy);
	if (dist <= (playerRadius + enemyRadius))
	{
		return true;
	}
	return false;
}

//プレイヤーの座標を表示する関数
void dispPlayerPos(const Player& player)
{
	int x = player.getPosX();
	int y = player.getPosY();
	DrawFormatString(8, 8, GetColor(255, 255, 255), "(%3d,%3d)", x, y);
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//一部の関数はDxlib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	player.init();

	Enemy enemy[kEnemyNum];
	
	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i].init();
		enemy[i].setPosX(kEnemyIntervalX * (i + 1));
	} 

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();
		
		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		//ゲーム処理
		player.update();
		for (int i = 0; i < kEnemyNum; i++)
		{
			enemy[i].update();


			//当たり判定
			
			float playerPosX = (float)player.getPosX();
			float playerPosY = (float)player.getPosY();
			float enemyPosX = (float)enemy[i].getPosX();
			float enemyPosY = (float)enemy[i].getPosY();

			float playerRadius = (float)player.getRadius();
			float enemyRadius = (float)enemy[i].getRadius();

			float dx = playerPosX - enemyPosX;
			float dy = playerPosY - enemyPosY;
			float dist = sqrtf(dx * dx + dy * dy);
			

			if (dist <= (playerRadius + enemyRadius))
			{
				enemy[i].redColor();
			}
			else
			{
				enemy[i].kDefaultColor();
			}

		}

	
		//描画
		player.draw();
		dispPlayerPos(player);

		// 画面が切り替わるのを待つ
		ScreenFlip();

		//escキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
		
		}


	}
	
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
#pragma once
#include"Player.h"
#include"Enemy.h"

//ゲームシーンのクラス化する
class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void Update();
	void Draw();
	void End();   //シーンの終了処理

	bool IsSceneEnd() const;
	bool IsCollison(const Player &player, const Enemy &enemy );

private:
	//画面内に同時に存在できる敵の最大数
	static constexpr int kEnemyMax = 30;

private:
	int m_playerHandle;
	int m_enemyHandle;
	bool m_IsSceneEnd;

	int m_bgmHandle;
	int m_enemyStartSe;

	Player m_player;
	Enemy m_enemy[kEnemyMax];

	bool m_isGameOver;  //ゲームオーバーかどうかのふらぐ
	int m_playFrameCount;  //生き残っている時間

	//雨粒の生成制御
	int m_enemyCreateNum;   //今までに生産した敵の数
	int m_enmeyWaitFrame;   //敵生成までの待ち時間

	//フェードイン、アウト
	int m_fadeAlpha;

	int m_bg;
};


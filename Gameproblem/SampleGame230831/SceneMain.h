#pragma once

class Player;
class EnemyRight;
class Bg;


class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void End();

	void Update();
	void Draw() const;

private:
	// メモリ確保する敵の数
	static constexpr int kEnemyNum = 16;

private:
	// グラフィックのハンドル
	int m_playerHandle;
	int m_enemyHandle;
	int m_bgHandle;

	Player* m_pPlayer;
//	EnemyRight* m_pEnemyRight;
	EnemyRight* m_pEnemyRight[kEnemyNum];

	// 
	int m_enemyFrameCount;

	//背景
	Bg* m_pBg;
};


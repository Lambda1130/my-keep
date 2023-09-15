#include "SceneMain.h"
#include"DxLib.h"
#include<cassert>
#include"Game.h"

namespace
{
	//ゲームオーバー時に表示する文字列
	const char* const kGameOverString = "ゲームオーーバーー";

	//敵の生成間隔(フレーム数)
	constexpr int kEnemytWaitFrameDefault = 30;
	//敵の最短生成間隔
	constexpr int kEnemyWaitFramwMin = 3;
	//敵の生成間隔を敵何体生成するたびに短くなるか
	constexpr int kEnemyWaitFramwChangeNum = 3;
	//一度生成間隔を短くする時に何フレーム短くするか
	constexpr int kEnemyWaitFrameChageFrame = 2;
}

SceneMain::SceneMain() :
	m_playerHandle(-1),
	m_enemyHandle(-1),
	m_bgmHandle(-1),
	m_enemyStartSe(-1),
	m_player(),    //クラスを初期化するとき、()の中にはコントラクタの引数を入れる
	              //Playerクラスに関してはコントラクタに引数がないので()でOK
	m_enemy(),
	m_isGameOver(false),
	m_playFrameCount(0),
	m_enemyCreateNum(0),
	m_enmeyWaitFrame(0),
	m_IsSceneEnd(false),
	m_fadeAlpha(255),
	m_bg(0)
{

}

SceneMain::~SceneMain()
{
	
}

void SceneMain::Init()
{
	ChangeFont("HGP創英ﾌﾟﾚｾﾞﾝｽEB");

	 m_playerHandle = LoadGraph("data/sound/player.png");
	 m_enemyHandle = LoadGraph("data/sound/enemy.png");
	 m_bg = LoadGraph("data/sound/aiue.jpg");

	 m_bgmHandle= LoadSoundMem("data/image/main.wav");
	 m_enemyStartSe = LoadSoundMem("data/image/enemy.mp3");

	 PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);

	 //フェードインさせるため音量0から始める
	 ChangeVolumeSoundMem(0, m_bgmHandle);

	 //プレイヤーの初期化
	 m_player.Init();
	 m_player.SetGraphHandle(m_playerHandle);

	 //敵の初期化
	 for (int i = 0; i < kEnemyMax; i++)
	 {
	     m_enemy[i].Init();
	     m_enemy[i].SetGraphHandle(m_enemyHandle);
	     m_enemy[i].SetStartPos();
	 }
	 m_isGameOver = false;
	 m_playFrameCount = false;
	 m_enemyCreateNum = 0;
	 m_enmeyWaitFrame = 0;
	 m_IsSceneEnd = 0;
	 m_fadeAlpha = 255;
}

void SceneMain::Update()
{
	int volume = 255 - m_fadeAlpha;
	ChangeVolumeSoundMem(volume, m_bgmHandle);

	if (m_isGameOver)
	{
		if (m_IsSceneEnd)
		{
			m_fadeAlpha += 8;
			if (m_fadeAlpha > 255)
			{
				m_fadeAlpha = 255;
			}
		}
	}

	//ゲームオーバーなら各処理を行わず、即Update()を終了させる
	if (m_isGameOver)
	{
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1)
		{
			m_IsSceneEnd = true;
		}
		return;
	}
	
	m_fadeAlpha -= 8;
	if (m_fadeAlpha < 0)
	{
		m_fadeAlpha = 0;
	}
	

	m_playFrameCount++;

	m_player.Update();
	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Update();

		if (IsCollison(m_player, m_enemy[i]))
		{
			m_isGameOver = true;
		}
	}

	m_enmeyWaitFrame++;

	//敵を一定数生成するたびに敵の生成間隔が短くなる
	int waitFrame = kEnemytWaitFrameDefault;
	waitFrame -= (m_enemyCreateNum / kEnemyWaitFramwChangeNum) * kEnemyWaitFrameChageFrame;
	//一番短い生成間隔のチェック
	if (waitFrame < kEnemyWaitFramwMin)  waitFrame = kEnemyWaitFramwMin;

	if (m_enmeyWaitFrame >= waitFrame)
	{
		//現在使われていない敵キャラクターを探して
		//そいつをstartさせる
		for (int i = 0; i < kEnemyMax; i++)
		{
			if (!m_enemy[i].isExist())
			{
				m_enemyCreateNum++;
				m_enmeyWaitFrame = 0;
				m_enemy[i].Start();

				//効果音
				PlaySoundMem(m_enemyStartSe,DX_PLAYTYPE_BACK);

				break;
			}
		}
	}
}

void SceneMain::Draw()
{

	m_player.Draw();
	for (int i = 0; i < kEnemyMax; i++)
	{
		m_enemy[i].Draw();
	}
	//生存期間を表示
	//分:秒ミリ秒
	int milliSec = m_playFrameCount * 1000 / 60;
	int sec = (milliSec / 1000)%60;
	int min = (milliSec / 1000) / 60;
	milliSec %= 1000;    //ミリ秒の部分のみ残す

	//文字列の横幅取得
	int strWidth = GetDrawFormatStringWidth("%d:%d.%d", min, sec, milliSec);

	DrawFormatString(Game::kSreenWidth / 2 - strWidth / 2, 
		Game::kSreenHeigt - 48, 
		GetColor(255, 255, 255),
		"%3d:%02d.%03d", min, sec, milliSec);

	if (m_isGameOver)
	{
		//画面中央にゲームオーバーを表示する
		int len = strlen(kGameOverString);
		int width = GetDrawStringWidth( kGameOverString, len);
		int height = GetFontSize();

		DrawString(Game::kSreenWidth/2-width/2, Game::kSreenHeigt/2-height/2,
			 kGameOverString, GetColor(255, 32, 32));
	}

	//フェードの描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeAlpha);
	DrawBox(0, 0, Game::kSreenWidth, Game::kSreenHeigt, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_fadeAlpha);
}

void SceneMain::End()
{
	DeleteGraph(m_enemyHandle);
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_bg);
	DeleteSoundMem(m_bgmHandle);
	DeleteSoundMem(m_enemyStartSe);

	StopSoundMem(m_bgmHandle);
}

bool SceneMain::IsSceneEnd() const
{
	return m_IsSceneEnd && (m_fadeAlpha>=255);
}

bool SceneMain::IsCollison(const Player& player, const Enemy& enemy)
{
	if (!enemy.isExist()) return false;

	//プレイヤーよりも完全に左側にいる場合は当たっていない
	//プレイヤー左側よりも左に敵の右端がある場合は当たっていない
	if (player.GetLeft() > enemy.GetRight())
	{
		//完全に左にいるので当たっていないこと確定
		return false;
	}
	//プレイヤーよりも完全に下にいる場合は当たっていない
	//プレイヤー下端よりも下に敵上端がある場合は当たっていない
	if (player.GetBottom() < enemy.GetTop())
	{
		return false;
	}
	//右
	if (player.GetRight() < enemy.GetLeft())
	{
		return false;
	}
	//上
	if (player.GetTop() > enemy.GetBottom())
	{
		return false;
	}
	return true;
}
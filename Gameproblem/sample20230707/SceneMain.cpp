#include "SceneMain.h"
#include"DxLib.h"
#include<cassert>
#include"Game.h"

namespace
{
	//�Q�[���I�[�o�[���ɕ\�����镶����
	const char* const kGameOverString = "�Q�[���I�[�[�o�[�[";

	//�G�̐����Ԋu(�t���[����)
	constexpr int kEnemytWaitFrameDefault = 30;
	//�G�̍ŒZ�����Ԋu
	constexpr int kEnemyWaitFramwMin = 3;
	//�G�̐����Ԋu��G���̐������邽�тɒZ���Ȃ邩
	constexpr int kEnemyWaitFramwChangeNum = 3;
	//��x�����Ԋu��Z�����鎞�ɉ��t���[���Z�����邩
	constexpr int kEnemyWaitFrameChageFrame = 2;
}

SceneMain::SceneMain() :
	m_playerHandle(-1),
	m_enemyHandle(-1),
	m_bgmHandle(-1),
	m_enemyStartSe(-1),
	m_player(),    //�N���X������������Ƃ��A()�̒��ɂ̓R���g���N�^�̈���������
	              //Player�N���X�Ɋւ��Ă̓R���g���N�^�Ɉ������Ȃ��̂�()��OK
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
	ChangeFont("HGP�n�p��ھ�ݽEB");

	 m_playerHandle = LoadGraph("data/sound/player.png");
	 m_enemyHandle = LoadGraph("data/sound/enemy.png");
	 m_bg = LoadGraph("data/sound/aiue.jpg");

	 m_bgmHandle= LoadSoundMem("data/image/main.wav");
	 m_enemyStartSe = LoadSoundMem("data/image/enemy.mp3");

	 PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);

	 //�t�F�[�h�C�������邽�߉���0����n�߂�
	 ChangeVolumeSoundMem(0, m_bgmHandle);

	 //�v���C���[�̏�����
	 m_player.Init();
	 m_player.SetGraphHandle(m_playerHandle);

	 //�G�̏�����
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

	//�Q�[���I�[�o�[�Ȃ�e�������s�킸�A��Update()���I��������
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

	//�G����萔�������邽�тɓG�̐����Ԋu���Z���Ȃ�
	int waitFrame = kEnemytWaitFrameDefault;
	waitFrame -= (m_enemyCreateNum / kEnemyWaitFramwChangeNum) * kEnemyWaitFrameChageFrame;
	//��ԒZ�������Ԋu�̃`�F�b�N
	if (waitFrame < kEnemyWaitFramwMin)  waitFrame = kEnemyWaitFramwMin;

	if (m_enmeyWaitFrame >= waitFrame)
	{
		//���ݎg���Ă��Ȃ��G�L�����N�^�[��T����
		//������start������
		for (int i = 0; i < kEnemyMax; i++)
		{
			if (!m_enemy[i].isExist())
			{
				m_enemyCreateNum++;
				m_enmeyWaitFrame = 0;
				m_enemy[i].Start();

				//���ʉ�
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
	//�������Ԃ�\��
	//��:�b�~���b
	int milliSec = m_playFrameCount * 1000 / 60;
	int sec = (milliSec / 1000)%60;
	int min = (milliSec / 1000) / 60;
	milliSec %= 1000;    //�~���b�̕����̂ݎc��

	//������̉����擾
	int strWidth = GetDrawFormatStringWidth("%d:%d.%d", min, sec, milliSec);

	DrawFormatString(Game::kSreenWidth / 2 - strWidth / 2, 
		Game::kSreenHeigt - 48, 
		GetColor(255, 255, 255),
		"%3d:%02d.%03d", min, sec, milliSec);

	if (m_isGameOver)
	{
		//��ʒ����ɃQ�[���I�[�o�[��\������
		int len = strlen(kGameOverString);
		int width = GetDrawStringWidth( kGameOverString, len);
		int height = GetFontSize();

		DrawString(Game::kSreenWidth/2-width/2, Game::kSreenHeigt/2-height/2,
			 kGameOverString, GetColor(255, 32, 32));
	}

	//�t�F�[�h�̕`��
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

	//�v���C���[�������S�ɍ����ɂ���ꍇ�͓������Ă��Ȃ�
	//�v���C���[�����������ɓG�̉E�[������ꍇ�͓������Ă��Ȃ�
	if (player.GetLeft() > enemy.GetRight())
	{
		//���S�ɍ��ɂ���̂œ������Ă��Ȃ����Ɗm��
		return false;
	}
	//�v���C���[�������S�ɉ��ɂ���ꍇ�͓������Ă��Ȃ�
	//�v���C���[���[�������ɓG��[������ꍇ�͓������Ă��Ȃ�
	if (player.GetBottom() < enemy.GetTop())
	{
		return false;
	}
	//�E
	if (player.GetRight() < enemy.GetLeft())
	{
		return false;
	}
	//��
	if (player.GetTop() > enemy.GetBottom())
	{
		return false;
	}
	return true;
}
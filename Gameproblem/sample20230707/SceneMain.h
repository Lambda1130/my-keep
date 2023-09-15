#pragma once
#include"Player.h"
#include"Enemy.h"

//�Q�[���V�[���̃N���X������
class SceneMain
{
public:
	SceneMain();
	~SceneMain();

	void Init();
	void Update();
	void Draw();
	void End();   //�V�[���̏I������

	bool IsSceneEnd() const;
	bool IsCollison(const Player &player, const Enemy &enemy );

private:
	//��ʓ��ɓ����ɑ��݂ł���G�̍ő吔
	static constexpr int kEnemyMax = 30;

private:
	int m_playerHandle;
	int m_enemyHandle;
	bool m_IsSceneEnd;

	int m_bgmHandle;
	int m_enemyStartSe;

	Player m_player;
	Enemy m_enemy[kEnemyMax];

	bool m_isGameOver;  //�Q�[���I�[�o�[���ǂ����̂ӂ炮
	int m_playFrameCount;  //�����c���Ă��鎞��

	//�J���̐�������
	int m_enemyCreateNum;   //���܂łɐ��Y�����G�̐�
	int m_enmeyWaitFrame;   //�G�����܂ł̑҂�����

	//�t�F�[�h�C���A�A�E�g
	int m_fadeAlpha;

	int m_bg;
};


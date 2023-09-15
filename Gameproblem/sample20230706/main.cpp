#include "DxLib.h"
#include"Enemy.h"

namespace
{
	//�G�̐�
	constexpr int kEnemyNum = 10;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Enemy enemy[kEnemyNum];

	//�O���t�B�b�N���\�[�X�̃��[�h
	int enemyHandle = LoadGraph("data/enemy.png");

	for (int i = 0; i < kEnemyNum; i++)
	{
	   enemy[i].Init();
	   enemy[i].SetHandle(enemyHandle);
	   enemy[i].SetStartPos();
	}

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		for (int i = 0; i < kEnemyNum; i++)
		{
		   enemy[i].Update();
		}

		

		//�`��
		for (int i = 0; i < kEnemyNum; i++)
		{
		   enemy[i].Draw();
		}


		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	//�O���t�B�b�N���\�[�X��������������
	DeleteGraph(enemyHandle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
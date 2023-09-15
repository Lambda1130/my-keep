#include "DxLib.h"
#include"Game.h"
#include"Enemy.h"
#include"Player.h"
#include<cassert>

#include"SceneManager.h"

namespace
{
	
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	//��ʂ̃T�C�Y�ύX
	SetGraphMode(Game::kSreenWidth, Game::kSreenHeigt, 32);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�V�[��
	SceneManager scene;
	scene.Init();

	while (ProcessMessage() != -1)
	{
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//���s���̃V�[���̍X�V�A�`����s��
		scene.Update();

		//�V�[���̐؂�ւ��s��
		scene.Draw();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}

	}

	
	scene.End();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}







/*
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	//��ʂ̃T�C�Y�ύX
	SetGraphMode(Game::kSreenWidth,Game::kSreenHeigt, 32);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[������
	int sceneNo = 0;   //���݂̃V�[����ϐ��Ŏ���
	                   //0:Title 1:Main
	                   //�{����enum���ł��ׂ�
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
	
	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		
				
		switch (sceneNo)
		{
		case 0:
			sceneTitle.Update();
			sceneTitle.Draw();
			if (sceneTitle.isEnd())
			{
				//�^�C�g���̏I��
				sceneTitle.End();

				//���̃V�[��
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

	sceneTitle.End();
	

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
*/




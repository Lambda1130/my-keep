#include "DxLib.h"
#include"SceneMain.h"

namespace
{
	constexpr int kRectNum = 32;
}
/*
//��`���m�̓����蔻��
bool IsCollision(const Rect& rect0, const Rect& rect1)
{
	rect0.GetRight();  //�v���C���[�̍��[��X���W
	rect1.GetRight();  //�Ώۂ̉E�[��X���W

	//rect0�̊��S�ɍ��ɂ���ꍇ�͓������Ă��Ȃ�
	if (rect0.GetLeft() > rect1.GetRight())
	{
		return false;
	}
	//rect0�̊��S�ɉ��ɂ���ꍇ�������Ă��Ȃ�
	if (rect0.GetBottom() < rect1.GetTop())
	{
		return false;
	}
	//rect0�̊��S�ɉE�ɂ���ꍇ�������Ă��Ȃ�
	if (rect0.GetRight() < rect1.GetLeft())
	{
		return false;
	}
	//rect0�̊��S�ɏ�ɂ���ꍇ�������Ă��Ȃ�
	if (rect0.GetTop() > rect1.GetBottom())
	{
		return false;
	}
	//���S�ɓ������Ă��Ȃ��p�^�[������菜����
	//�c������͓������Ă���
	return true;
}
*/

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

	SceneMain sceneMain;

	sceneMain.Init();

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		sceneMain.Update();

		//�`��
		sceneMain.Draw();

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

	sceneMain.End();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
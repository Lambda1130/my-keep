#include "DxLib.h"

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

	int handle = LoadGraph("mizuki.gif");
	int fadeAlpha = 255; //�s��������n�߂�
	int fadeSpeed = -1;  //�����x�����߂�
	
	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		fadeAlpha+=fadeSpeed;
		if(fadeAlpha<0)
		{
			//���S�Ƀt�F�[�h�C������
			fadeAlpha = 0;
			//���̃t���[������̓t�F�[�h�A�E�g
			fadeSpeed = 1;
		}
		if (fadeAlpha > 255)
		{
			//�����x�Ƀt�F�[�h�A�E�g
			fadeAlpha=255;
		}

		//�������@DX_BLENDMODE_ALPHA:�������ŕ\��������
		//��2�����@DX_BLENDMODE_ALPHA���w�肢��ꍇ
		//         �ǂ̂��炢�̓����x�ŕ\�����邩�A���w�肷��  0~255
		//         0:���S�ɓ��� 255:�s����
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 0, handle, true);

		//SetDrawBlendMode�œ����ɂ��������̂�\��������
		//�ȍ~�̕��̂��������ɂȂ�Ȃ��悤
		//DX_BLENDMODE_ALPHA�ɖ߂��Ă���
		//�������͂ɉ����w�肵�Ă�����
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		//SetDrawBlendMode�������ɂ������I�Ǝw�肷��ƁA
		//�ȍ~�S�Ă̕������������x�ŕ\�������
		//DrawBox(0, 0, 640, 240, GetColor(255, 255, 0), true);   //��ʏ㔼���𕢂��l�p

		//�t�F�[�h�C���@�A���t�@��255����O�ɕϊ�������
		//�t�F�[�h�p�̍��l�p��\��
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
		DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);

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

	DeleteGraph(handle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
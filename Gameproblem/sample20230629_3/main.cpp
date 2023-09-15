#include "DxLib.h"
#include "player.h"
#include  "enemy.h"
#include <cmath>

namespace
{
	//�G�̐�
	constexpr int kEnemyNum = 3;
	//�G�̈ʒu���
	constexpr int kEnemyIntervalX = 160;
}

//�v���C���[�ƓG���������Ă��邩���肷��
//�N���X�A�\���̂������Ƃ��ēn���ꍇ�̓|�C���^�A�Q�Ɠn������
//�l�n�����ƃf�[�^�̃R�s�[�Ɏ��Ԃ������邽��
bool isCollision(Player& player, Enemy& enemy)
{
	//����ɕK�v�ȃv���C���[
	float playerPosX = (float)player.getPosX();
	float playerPosY = (float)player.getPosY();
	float playerRadius = (float)player.getRadius();

	//�G�̏��
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

//�v���C���[�̍��W��\������֐�
void dispPlayerPos(const Player& player)
{
	int x = player.getPosX();
	int y = player.getPosY();
	DrawFormatString(8, 8, GetColor(255, 255, 255), "(%3d,%3d)", x, y);
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�ꕔ�̊֐���Dxlib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();
		
		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//�Q�[������
		player.update();
		for (int i = 0; i < kEnemyNum; i++)
		{
			enemy[i].update();


			//�����蔻��
			
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

	
		//�`��
		player.draw();
		dispPlayerPos(player);

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŏI��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
		
		}


	}
	
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
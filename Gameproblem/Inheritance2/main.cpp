#include<iostream>
#include"Class.h"
using  namespace std;

namespace
{
	//��x�ɓo�ꂷ��G�̍ő吔
	constexpr int kEnemyMax = 8;
}

//�h���S�g���N�G�X�g�퓬��ʂ̎���������������
int main()
{
	cout << "�p���旘�p����" << endl;

	//EnemyBase�ɂ͂ǂ̓G�ł�����邱�Ƃ��ł���̂�
	//��x�ɓo�ꂷ��ő吔�������Ă�����ok
	EnemyBase* pEnemy[kEnemyMax];
	for (int i = 0; i < kEnemyMax; i++)
	{
		//pEnemy[i]== nulltpr�̏ꍇ�A�ȍ~�̏������s�킸�Ɏ��̃��[�v��
		if (pEnemy[i])  continue;

		cout << pEnemy[i]->GetName() << "�������ꂽ" << endl;
	}

	pEnemy[0] = new EnemySlime;
	pEnemy[1] = new EnemyDorakey;
	pEnemy[2] = new EnemyDoragon;

	//�m�ۂ����������̊J��
	for (int i = 0; i < kEnemyMax; i++)
	{
		if (pEnemy[i])
		{
			delete pEnemy[i];
			pEnemy[i] = nullptr;
		}

	}

	return 0;
}


#if false
//�p������悤���ā��̂������ƃX�}�[�g�ɏ���
int main()
{
	cout << "�p���旘�p����" << endl;

	//EnemySlime�^�̃|�C���^�ɂ�EnemySlime���A
	//EnemyDorakey�^�̃|�C���^�ɂ�EnemyDorakey����ꂽ���i�������l�j
	//�|�C���^�̌^�̂Ƃ��̎w��������̃f�[�^�^�͈�v���Ă��Ȃ��Ƃ����Ȃ�

	//������������������������������������������������������������
	//�p�����s���ăN���X���쐬�����ꍇ
	//���N���X�̃|�C���^�Ɍp����̃|�C���^���i�[���邱�Ƃ��ł���
	//������������������������������������������������������������
//	EnemyBase*pEnemy=new EnemyBase //���܂�:�|�C���^�Ǝ��ۂɊm�ۂ���f�[�^�^��v
	EnemyBase* pEnemy = new EnemySlime; //���N���X�̃|�C���^�ɂ��̌p����̃|�C���^���i�[

//	EnemyBase* pEnemy = new EnemyDorakey;
//	EnemyBase* pEnemy = new EnemyDoragon;

	delete pEnemy;
	pEnemy = nullptr;

	return 0;
}
#endif

#if false
//�h���S���N�G�X�g�̐퓬��ʂ��ǂ����s����H
//�y���𗘗p���Ȃ��Ƃ���Ȋ�����
int main()
{
	cout << "�p���旘�p����" << endl;

	EnemySlime* pSlime[8];
	EnemyDorakey* pDorakey[8];
	EnemyDoragon* pDoragon[3];
	//�����X�^�[�̐����������..
	//�������̊m�ۂ͌��ꂽ�����X�^�[�̕��݂̂���΂悢��
	// �|�C���^�[�̓����X�^�[�̎�ށ���x�Ɍ���鐔�������Ȃ��Ƃ����Ȃ��H
	

	//�����X�^�[�����ꂼ��1�̂������
	pSlime[0] = new EnemySlime;
	pDorakey[0] = new EnemyDorakey;
	pDoragon[0] = new EnemyDoragon;

	//�S��GetName()���Ă���񂾂���for���ł܂킵����
	cout << pSlime[0]->GetName() << "�������ꂽ�I" << endl;
	cout << pDorakey[0]->GetName() << "�������ꂽ�I" << endl;
	cout << pDoragon[0]->GetName() << "�������ꂽ�I" << endl;


	return 0;
}
#endif
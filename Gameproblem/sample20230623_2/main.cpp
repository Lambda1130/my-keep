#include<iostream>
using namespace std;

//�g���̔z���n���Ă��ꂼ��̕W���̏d��\������֐��@�g��-105��\��
//�ϐ�����|�C���^�̐錾�O��const�����邱�Ƃł��̒��g��ύX���邱�Ƃ��ł��Ȃ��Ȃ�
void dispStandardWaight(const int height[])
{
	cout << "�W���̏d" << endl;
	for (int i = 0; i < 3; i++)
	{
		int stdWeight = height[i] - 105;
		cout << i + 1 << ":" << height[i] << endl;
	}
}

//�g����\������֐�
void dispHeight(const int height[])
{
	cout << "�g��" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ":" << height[i] << endl;
	}
}

struct Test
{
	int testDate0;
	int testDate1;
};

//�|�C���^��Q�Ƃ�const�ɂ���Ƃ��̃����o�[���ύX�ł��Ȃ��Ȃ�
void testFunc(Test* pTest)
{
	pTest->testDate0 = 100;
	pTest->testDate1 = 100;
}

int main()
{
	Test test;
	testFunc(&test);
}

int main()
{
#if false
	//3�l���̐g���f�[�^
	int height[3] = { 170,180,190 };

	//�W���̏d��\������
	dispStandardWaight(height);

	//�g���f�[�^��\������
	dispHeight(height);
#endif
	return 0;
}
#include<iostream>
using namespace std;

void add_1(int x)
{
	x += 1;
}
//�|�C���^�n�����g�p�����֐�
void add_2(int* pX)
{
	*pX += 2;
}

//�Q�Ɠn�����g�p�����֐�
void add_3(int& x)
{
	//�K����������ϐ����Q�Ƃ��Ă���̂�
	//�`�F�b�N�Ȃǂ͕s�v
	x += 3;
}

int main()
{
	int num = 123;
	cout << "num=" << num << endl;
	
	add_1(num);
	cout << "add_1:" << num << endl;

	add_2(& num);   //�|�C���^�n��num�ω�����
	cout << "add_2:" << num << endl;

	add_3(num);
	cout << "add_3:" << num << endl;

	//�Q�Ƃ��g���Ă݂�
	int& refNum = num;
	cout << "refNum=" << refNum << endl;

	refNum -= 100;
	cout << "num=" << num << endl;
	cout << "refNum=" << refNum << endl;

	refNum += 1000;
	cout << "num=" << num << endl;
	cout << "refNum=" << refNum << endl;

	cout << endl;

	//�Q�Ƃ̒��ӓ_�@�Q�Ɛ�̕ύX�͂ł��Ȃ�
	int num2 = 999;

	int* pNum = &num;
	pNum = &num2;

	refNum = num2;
	cout << "refNum=" << refNum << endl;

	//�Q�Ɛ�͕K�����������ɐݒ肷��
//	int& refNum2;   //ng �������ɎQ�Ɛ��ݒ肷��K�v������
	int& refNum2 = num2;  //�K���Q�Ɛ��ݒ肷��

	int* pNum2;    //�|�C���^�͐������ɏ������s�v
	cout << "pNum2=" << (*pNum2) << endl;

	return 0;
}
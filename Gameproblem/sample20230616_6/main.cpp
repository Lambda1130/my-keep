#include<iostream>
#include<cmath>   //���w�֘A

using namespace std;

int main()
{
	//���p�O�p�`�̎Εӂ̒����̂����߂�v���O����
	double a, b;     //��ӂƍ���

	cout << "���p���͂���2�ӂ̒�������͂��Ă�������" << flush;
	cin >> a >> b;

	//�Εӂ̒������v�Z����
	double result = sqrt(a * a + b + b);    //aqrt(x)��x�̕����������߂�
	cout << "�Εӂ̒�����" << result << "�ł�" << endl;

	//ads(x)    x:�̐�Βl�����߂�
	//floor(x)  �����_�ȉ��؂�̂�
	//cell(x)�@�@�����_�ȉ��؂�グ
	//fmod(x,y)  �������Ŋ������]��
	//sqrt(x)    ������
	//......140P

	return 0;
}
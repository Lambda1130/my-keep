#include<iostream>
using namespace std;

//��������a�ɕϊ�����֐�
//���a�ł͂Ȃ��N���w�肳�ꂽ�ꍇ�O�ɂ���
void WestenToShouwa(int& x)
{
	if (x >= 1926 && x <= 1989)
	{
		x -= 1925;
    }
	else
	{
		x = 0;
	}
}

void Shouwa(void)
{
	int year;

	cout << "�������͂��Ă�������>" << flush;
	cin >> year;   //�L�[�{�[�h���琔�l����͂��� 

	//	cout << "����:" << year << endl;
	WestenToShouwa(year);
	if (year != 0)
	{
		cout << "���̔N�͏��a" << year << "�N�ł�" << endl;
	}
	else
	{
		cout << "���̔N�͏��a�ł͂���܂���" << endl;
	}
}
int main()
{
	Shouwa();
	int year;

	cout << "�������͂��Ă�������>" << flush;
	cin >> year;   //�L�[�{�[�h���琔�l����͂��� 

	//	cout << "����:" << year << endl;
	WestenToShouwa(year);
	if (year != 0)
	{
		cout << "���̔N�͏��a" << year << "�N�ł�" << endl;
	}
	else
	{
		cout << "���̔N�͏��a�ł͂���܂���" << endl;
	}

	return 0;
}
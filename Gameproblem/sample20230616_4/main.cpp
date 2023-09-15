#include<iostream>
using namespace std;

//西暦を昭和に変換する関数
//昭和ではない年が指定された場合０にする
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

	cout << "西暦を入力してください>" << flush;
	cin >> year;   //キーボードから数値を入力する 

	//	cout << "入力:" << year << endl;
	WestenToShouwa(year);
	if (year != 0)
	{
		cout << "その年は昭和" << year << "年です" << endl;
	}
	else
	{
		cout << "その年は昭和ではありません" << endl;
	}
}
int main()
{
	Shouwa();
	int year;

	cout << "西暦を入力してください>" << flush;
	cin >> year;   //キーボードから数値を入力する 

	//	cout << "入力:" << year << endl;
	WestenToShouwa(year);
	if (year != 0)
	{
		cout << "その年は昭和" << year << "年です" << endl;
	}
	else
	{
		cout << "その年は昭和ではありません" << endl;
	}

	return 0;
}
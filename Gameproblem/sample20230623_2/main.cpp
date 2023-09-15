#include<iostream>
using namespace std;

//身長の配列を渡してそれぞれの標準体重を表示する関数　身長-105を表示
//変数名やポインタの宣言前にconstをつけることでその中身を変更することができなくなる
void dispStandardWaight(const int height[])
{
	cout << "標準体重" << endl;
	for (int i = 0; i < 3; i++)
	{
		int stdWeight = height[i] - 105;
		cout << i + 1 << ":" << height[i] << endl;
	}
}

//身長を表示する関数
void dispHeight(const int height[])
{
	cout << "身長" << endl;
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

//ポインタや参照をconstにするとそのメンバーが変更できなくなる
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
	//3人分の身長データ
	int height[3] = { 170,180,190 };

	//標準体重を表示する
	dispStandardWaight(height);

	//身長データを表示する
	dispHeight(height);
#endif
	return 0;
}
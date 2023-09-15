#include<iostream>
using namespace std;

void add_1(int x)
{
	x += 1;
}
//ポインタ渡しを使用した関数
void add_2(int* pX)
{
	*pX += 2;
}

//参照渡しを使用した関数
void add_3(int& x)
{
	//必ず何かしら変数を参照しているので
	//チェックなどは不要
	x += 3;
}

int main()
{
	int num = 123;
	cout << "num=" << num << endl;
	
	add_1(num);
	cout << "add_1:" << num << endl;

	add_2(& num);   //ポインタ渡しnum変化する
	cout << "add_2:" << num << endl;

	add_3(num);
	cout << "add_3:" << num << endl;

	//参照を使ってみる
	int& refNum = num;
	cout << "refNum=" << refNum << endl;

	refNum -= 100;
	cout << "num=" << num << endl;
	cout << "refNum=" << refNum << endl;

	refNum += 1000;
	cout << "num=" << num << endl;
	cout << "refNum=" << refNum << endl;

	cout << endl;

	//参照の注意点　参照先の変更はできない
	int num2 = 999;

	int* pNum = &num;
	pNum = &num2;

	refNum = num2;
	cout << "refNum=" << refNum << endl;

	//参照先は必ず初期化時に設定する
//	int& refNum2;   //ng 生成時に参照先を設定する必要がある
	int& refNum2 = num2;  //必ず参照先を設定する

	int* pNum2;    //ポインタは生成時に初期化不要
	cout << "pNum2=" << (*pNum2) << endl;

	return 0;
}
#include<iostream>
#include<cmath>   //数学関連

using namespace std;

int main()
{
	//直角三角形の斜辺の長さのを求めるプログラム
	double a, b;     //底辺と高さ

	cout << "直角をはさむ2辺の長さを入力してください" << flush;
	cin >> a >> b;

	//斜辺の長さを計算する
	double result = sqrt(a * a + b + b);    //aqrt(x)でxの平方根を求める
	cout << "斜辺の長さは" << result << "です" << endl;

	//ads(x)    x:の絶対値を求める
	//floor(x)  小数点以下切り捨て
	//cell(x)　　小数点以下切り上げ
	//fmod(x,y)  ｘをｙで割った余り
	//sqrt(x)    平方根
	//......140P

	return 0;
}
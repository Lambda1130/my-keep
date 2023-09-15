#include<iostream>
using namespace std;

//c++不定数定義
//const int kArraySize = 5;

//現代的c++の定数定義
namespace
{
	constexpr int kConstextprNum = 3;   //constexpr:定数を定義するために準備された書き方
                                     	//コンパイル時点で値が決まっている場合はこっち
	const int kConstNum = 3;            //const:変数の変更を不可能にするための書き方
                                       	//最初に決めた値から変更できないという性質を利用して
}                                       //定数定義に使用したいた

//定数定義のまとめ
//namespace(無名名前空間　名前が設定されていないnamespace)の中に入れる
//無名名前空間の中に書いている変数や定数、関数はそのソースコードでのみ有効
namespace
{
	//基本的に敵数はconstexprで定義する
	//定数名はgoogleのコーディング規約準拠
	//定数名の命名規則はほかのルールが良いならそれでいいが必ず統一すること
	constexpr int kNum = 16;

	constexpr int kDoubleNum = kNum * 2;  //定数を使用して定数を定義することも可能
	constexpr float kFloatNum = 12.25f;  //int以外もOk

	//当たり判定のサイズ
	constexpr float kRadius = 8.0f;

	//namespace終了時セミコロン不要
}

namespace
{
	constexpr int kEnemyNum = 16;
}

//通常のnamespaceの書き方
//namespaceの後に名前を設定する
namespace Test
{
	int num = 10;
}

//文字列を定数として定義したい
const char* const kConstText = "定数として定義された文字列";
const char* const KFileName = "data/image.png";   //ファイル名を定義する

//pNumの参照先変更不可
//pNumの中身固定ではない　初期化はできるということ
void func(const int* num)
{

}

int main()
{
	//constexpr, const共に値を変更する
//	kConstextprNum = 10;
//	kConstNum = 10;

	//constは初期化できる
	const int constNum = rand() % 16;
	//後から変更はできない
//	constNum = 10;

	//ng　コンパイルした時点で値が決まらない
//	constexpr int constexprNum = rand() % 16;

	//定数定義はconstexprをつかう
	//それ以外の変更してほしくない値はconstをつかう

#if false
	int tbl[kArraySize] = { 10,20,30 };
	
	for (int i = 0; i < kArraySize; i++)
	{
		cout << tbl[i] << endl;
	}
#endif
	return 0;
}
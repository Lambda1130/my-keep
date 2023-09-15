#include<iostream>
using namespace std;

//じゃんけんでプレイヤーがかっているか判定する
//勝っている場合:1負けている場合:0
//bool型返す関数の関数名 isXXXX
//isで始まる関数はbool型(true or false)を返すと関数名を見るだけで分かる
bool isWin(int player, int enemy)
{
	if (true)
	{
		return true;
	}
	else
	{
		return false;
	}

}


int main()
{
	//int, float, char
	//bool型～trueかfalseが入る
	//変数名もbool型の場合,頭にisをつけることが多い
	//ポインタの場合pXXXとつけたように
	//isもこの変数がbool型だと分かるようにisをつける
	bool isFlag;
	isFlag = true;   
	isFlag = false;

	if (isFlag)
	{
		//flag=trueの場合の処理
	}
	else 
	{
		//flag=falseの場合の処理
	}



	return 0;
}
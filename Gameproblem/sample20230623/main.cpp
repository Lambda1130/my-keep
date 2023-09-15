#include<iostream>
using namespace std;

void printMsg(void)
{
	cout << "test" << endl;
}

//NG 戻り値が違うだけの同名関数は作成できない

//void printMsg(void)
//{
//	cout << "test2" << endl;
//	return 10;
//}


//void printMsg(int score=50)   //ng 引数を省略した場合、引数なしと見分けがつかないのでng
void printMsg(int num, int score=50)
{
	cout << "テスト点:" <<score<< endl;
}

//void printMsg(int num)  //ng 引数２つ＆2つ目がデフォルト引数、と見分けがつかないのでNg
//{
//	cout << "num:" << num << endl;
//}

//c++では関数の引数にデフォルトの値を設定できる
struct Player
{
	int hp;
	int mp;
};

//仮引数の後に＝５０のように省略した場合に設定される数値を指定できる
// これをデフォルト引数という
// デフォルト引数が設定されている場合、引数省略することができる
//省略した場合、仮引数には設定した値が入る
void initPlayer(Player& player, int hp=100, int mp=50)
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{
	printMsg();
	printMsg(10);
	printMsg(10,50);


	Player player;
	initPlayer(player);

	//キャラクター選択可能
	//１００種類キャラクターがいる
	//1体は体力自慢      hp200, mp0
	//1体は魔法使い      hp50,  mp100
	//それ以外の９８体は hp100, mp50

	cout << "HP:" << player.hp << endl;
	cout << "MP:" << player.mp << endl;

	return 0;
}
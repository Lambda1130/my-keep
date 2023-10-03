#include<iostream>
#include"Class.h"
using  namespace std;

namespace
{
	//一度に登場する敵の最大数
	constexpr int kEnemyMax = 8;
}

//ドラゴトンクエスト戦闘画面の実装を書き換える
int main()
{
	cout << "継承先利用する" << endl;

	//EnemyBaseにはどの敵でも入れることができるので
	//一度に登場する最大数準備しておけばok
	EnemyBase* pEnemy[kEnemyMax];
	for (int i = 0; i < kEnemyMax; i++)
	{
		//pEnemy[i]== nulltprの場合、以降の処理を行わずに次のループへ
		if (pEnemy[i])  continue;

		cout << pEnemy[i]->GetName() << "があらわれた" << endl;
	}

	pEnemy[0] = new EnemySlime;
	pEnemy[1] = new EnemyDorakey;
	pEnemy[2] = new EnemyDoragon;

	//確保したメモリの開放
	for (int i = 0; i < kEnemyMax; i++)
	{
		if (pEnemy[i])
		{
			delete pEnemy[i];
			pEnemy[i] = nullptr;
		}

	}

	return 0;
}


#if false
//継承をりようして↓のをもっとスマートに書く
int main()
{
	cout << "継承先利用する" << endl;

	//EnemySlime型のポインタにはEnemySlimeを、
	//EnemyDorakey型のポインタにはEnemyDorakeyを入れたい（他も同様）
	//ポインタの型のとその指し示す先のデータ型は一致していないといけない

	//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
	//継承を行ってクラスを作成した場合
	//基底クラスのポインタに継承先のポインタを格納することができる
	//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
//	EnemyBase*pEnemy=new EnemyBase //今まで:ポインタと実際に確保するデータ型一致
	EnemyBase* pEnemy = new EnemySlime; //基底クラスのポインタにその継承先のポインタを格納

//	EnemyBase* pEnemy = new EnemyDorakey;
//	EnemyBase* pEnemy = new EnemyDoragon;

	delete pEnemy;
	pEnemy = nullptr;

	return 0;
}
#endif

#if false
//ドラゴンクエストの戦闘画面をどう実行する？
//軽傷を利用しないとこんな感じに
int main()
{
	cout << "継承先利用する" << endl;

	EnemySlime* pSlime[8];
	EnemyDorakey* pDorakey[8];
	EnemyDoragon* pDoragon[3];
	//モンスターの数が増えると..
	//メモリの確保は現れたモンスターの分のみすればよいが
	// ポインターはモンスターの種類＊一度に現れる数準備しないといけない？
	

	//モンスターがそれぞれ1体ずつ現れる
	pSlime[0] = new EnemySlime;
	pDorakey[0] = new EnemyDorakey;
	pDoragon[0] = new EnemyDoragon;

	//全員GetName()しているんだからfor文でまわしたい
	cout << pSlime[0]->GetName() << "があらわれた！" << endl;
	cout << pDorakey[0]->GetName() << "があらわれた！" << endl;
	cout << pDoragon[0]->GetName() << "があらわれた！" << endl;


	return 0;
}
#endif
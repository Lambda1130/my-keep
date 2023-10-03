#pragma once
#include<iostream>
using namespace std;

//モンスターの基底クラス
class EnemyBase
{
public:
	EnemyBase(){}
	~EnemyBase() { cout << "Base" << endl; }

	//上書き（overraide）したい関数の頭に
	//virtualをつける

	//EnemyBaseというEnemyを生成することはない
	//なのでGetName()は必ず上書きしてほしい
	//絶対に上書きしてほしい関数は『純粋仮想関数』にする
	//純粋仮想関数は関数に＝０とかく
	virtual const char* GetName() = 0;
//	virtual const char* GetName() { return "ななし"; }

protected:
	int m_hp = 0; //こんな初期化も可能

};

//スライム
class EnemySlime : public EnemyBase
{
public:
	EnemySlime(){}
	virtual ~EnemySlime() { cout << "Slime" << endl; }
	//スライムを継承してスライムベスを作る『可能性がある』
	//ので一応virtualにしておく
	virtual const char* GetName() override { return "スライム"; }
};

//ドラゴン
class EnemyDorakey : public EnemyBase
{
public:
	EnemyDorakey() {}
	~EnemyDorakey() {}

	virtual const char* GetName() override { return "ドラキー"; }
};

//ドラゴン
class EnemyDoragon : public EnemyBase
{
public:
	EnemyDoragon(){}
	~EnemyDoragon(){}

	virtual const char* GetName() override { return "ドラゴン"; }
};
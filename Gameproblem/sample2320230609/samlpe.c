#include<stdio.h>

typedef struct Unit
{
	int level;
	int hp;
	int mp; 
	int atk;
	int def;
}Unit;

//ユニットのステータスを表示する関数
//構造体を引数として渡す
void dispStatus(Unit unit)
{
	printf("レベル:%d\n", unit.level);
	printf("HP:%d\n", unit.hp);
	printf("MP:%d\n", unit.mp);
	printf("攻撃:%d\n", unit.atk);
	printf("防御:%d\n", unit.def);


}
	
//ユニットのレベル上げる
//関数の内部で渡された構造体の中身を変更したい
//構造体のポインタを受け取る
void levelUp(Unit* pUnit)
{
	//構造体のポインタから
	//そのメンバにアクセスしたい
	//アロー演算子を利用する
	if (pUnit->level >= 99) return;

	pUnit->level++;
	pUnit->hp+=5;
	pUnit->mp+=5;
	pUnit->atk+=5;
	pUnit->def+=5;
}

int main(void)
{
	//構造体の配列
	Unit unitTbl[3];

	//初期ステータスの設定
	for (int i = 0; i < 3; i++)
	{
		unitTbl[i].level = 1+i;
		unitTbl[i].hp = 50;
		unitTbl[i].mp = 10;
		unitTbl[i].atk = 15;
		unitTbl[i].def = 10;
	}

	//ステータスの表示
	for (int i = 0; i < 3; i++)
	{
		dispStatus(unitTbl[i]);

	}

	/*
	Unit unit = { 1,50,20,20,10 };

	dispStatus(unit);
	levelUp(&unit);
	dispStatus(unit);
	*/

	return 0;
}

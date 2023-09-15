#pragma once

//1クラス１ファイルを心掛ける

//なぜわざわざクラスのメンバをprivateにするの？
//すべてpublicなら便利では？

//const　　値をいじれないようにする
//値をいじれたほうが便利　→間違えていじる事を防ぐためにconstでそもそもいじれないようにする

//*クラスの処理はクラス自身にやらせる
//⋆外から勝手に値をいじられないようにする
// 例.敵を非表示したい　勝手に画面外の座標に移動させる、みたいなことが発生する→敵は生きているはずなのに画面に表示されない？といったバグ

class Enemy
{
public:
	//コンストラクタ、デストラクタは特殊な事をしない限りpublic
	Enemy();
	~Enemy();

	//クラス外から使いたい（今回はWINMainで使う）ものはpublic
	void init();
	void draw();

	//クラス外からメンバ変数を変更したい場合はpublicなメンバ変数を通す
	void setPos(int x, int y);

	//簡単な中身ならヘッダに直接書くことも多い
	void setPosX(int x) { m_posX = x; }
	void setPosY(int y) { m_posY = y; }

private:
	//メンバー変数はすべてprivate
	int m_handle;
	int m_posX;
	int m_posY;
};

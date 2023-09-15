#pragma once

class Cirle
{
public:
	Cirle();  //コンストラクタ　メモリが確保されたとき自動的に呼ばれる関数
	~Cirle(); //デストラクタ　メモリが解放されるときに自動的に呼ばれる

	void init();
	void update();
	void draw();

	//メンバ変数の値を取得したい場合はpublicは関数経由で行う
	bool isExit() { return m_isExist; }

	//円のサイズを小さくする
	void smaller(int size);

	//set,get関数は定番
	int getPosX() { return m_posX; }
	void setPosX(int x) { m_posX = x; }

	//メンバ変数は必ずprivateにする
private:
	int m_posX;
	int m_posY;
	
	//半径
	int m_radius;

	//
	bool m_isLasMouseDown;

	//マウスカーソルが円の中にあるか
	bool m_isMouseIn;

	//この円が存在しているか
	bool m_isExist;
};
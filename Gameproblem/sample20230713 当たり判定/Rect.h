#pragma once
class Rect
{
public:
	Rect();
	~Rect();

	void Init();
	void Update();
	void Draw();

	//画面内のランダムな位置にランダムな大きさの矩形データを設定する
	void SetRandom();

	//他の矩形との当たり判定
	//自身と指定した他の矩形の当たり判定を取る
	bool IsCollision(const Rect& target)const;

	//publicな関数経由でメンバー変数を変更
	void SetColor(unsigned int color) { m_color = color; }
	void SetFill(bool isFill) { m_isFill = isFill; }
	void SetMouseTrase(bool isTrase) { m_isMoreTrase = isTrase; }

//	void setPosX(int x) { m_posX = x; }
//	void setPosX(int y) { m_posX = y; }

	//当たり判定実装用に上下左右の座標を取得できるようにする
	int GetLeft()const;
	int GetTop()const;
	int GetRight()const;
	int GetBottom()const;

private:
	//中心座標と幅、高さで管理する
	int m_posX;  //m_centerみたいなもの良いかも
	int m_posY;
	int m_width;
	int m_height;

	//色
	unsigned int m_color;
	//塗りつぶしフラグ
	bool m_isFill;

	//マウス追従フラグ
	bool m_isMoreTrase;
};


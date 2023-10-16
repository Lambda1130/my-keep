#pragma once
#include"Vec2.h"

//短形の座標を管理するためのクラス
class Rect
{
public:
	Rect();
	virtual ~Rect();

	void Draw(unsigned int color, bool isFill);

	//左上座標と幅高さを指定
	void SetLT(float left, float top, float width, float bottom);
	//ゲームによって中心座標で指定したり足元の座標で指定する

	//中心座標と幅高さを指定
	void SetCenter(float x, float y, float width, float height);

	//必要な情報を取得する
	float GetWidth() const;   //矩形の幅
	float GetHeight() const;  //矩形の高さ
	Vec2 GetCenter() const;   //矩形の中心座標

	//矩形同士の当たり判定
	bool IsCollsion(const Rect& rect);

private:
	float m_left;   //左上のX座標
	float m_top;    //左上のY座標
	float m_rigth;  //右下のX座標
	float m_bottom; //右下のY座標

private:
	int m_colrect;
};


#include"Circleh.h"
#include"DxLib.h"
#include<cmath>

namespace
{
	//円の初期化半径
	constexpr int kRadiusDefault = 64;
	//最小サイズ
	constexpr int kRadiusMin = 12;
}

Cirle::Cirle():
	m_posX(0),
	m_posY(0),
	m_radius(64),
	m_isLasMouseDown(true),
	m_isMouseIn(false),
	m_isExist(true)
{

	//rand()の時と使い方勝手が違うので気を付ける
//	int num = rand() % 64;  //0~63
//	int num2 = GetRand(64);
}

Cirle::~Cirle()
{

}

void Cirle::init()
{
	m_posX=GetRand(640 - m_radius * 2) + m_radius;
	m_posY=GetRand(480 - m_radius * 2) + m_radius;
	m_isExist = true;
}

void Cirle::update()
{
	//マウスがクリックされている状態を取得
	bool isClick = false;
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) !=0)
	{
		isClick = true;
	}

	if (!m_isExist)
	{
		m_isLasMouseDown = isClick;
		return;
	}
	//マウスカーソル位置取得
	int mouseX;
	int mouseY;
	GetMousePoint(&mouseX, &mouseY);

	//(float)num :C言語風キャスト　c++では使わない
	//static_cast<float>(num) :C++のキャスト static_以外のキャストもあるがそれはおいおい
	float dx =static_cast<float>(mouseX - m_posX);
	float dy =static_cast<float>(mouseY - m_posY);

	if (sqrtf(dx * dx + dy * dy)<m_radius)
	{
		//マウスカーソルが円の中にある
		m_isMouseIn = true;
	}
	else
	{
		m_isMouseIn = false;
	}

	//クリックした判定
	if (isClick && !m_isLasMouseDown)
	{
		if(m_isMouseIn)   //カーソルが円の中にある状態でクリックした
		{
			//円を消す
			m_isExist = false;
		}
		
	}
	//
	m_isLasMouseDown=isClick;
}

void Cirle::draw()
{
	if (!m_isExist)  return;

	unsigned int color=GetColor(255,255,255);
	if (m_isMouseIn)
	{
		color = GetColor(255, 255, 0);
	}
		DrawCircle(m_posX, m_posY, m_radius,color, true);

		//
		DrawFormatString(0, 0, GetColor(255, 255, 255),
			"pos(%d,%d)", m_posX, m_posY);
}

void Cirle::smaller(int size)
{
	m_radius -= size;
	//サイズの下限を設定する
	if (m_radius < kRadiusMin)
	{
		m_radius = kRadiusMin;
	}
}
#pragma once
#include<cmath>

//ƒxƒNƒgƒ‹‚ğ•Ö—˜‚Éˆµ‚¤‚½‚ß‚ÌƒNƒ‰ƒX
class Vec2
{
public:
	float x;
	float y;

public:
	Vec2() :
		x(0.0f),
		y(0.0f)
	{
	}

	Vec2(float posX, float posY) :
		x(posX),
		y(posY)
	{
	}

	////‘«‚µZ
	//Vec2 plus(Vec2 vec)
	//{
	//	Vec2 result{ x + vec.x,y + vec.y };
	//	return result;
	//}

	//’P€‰‰Zq- Vec2=-Vec2
	Vec2 operator+() const
	{

	}


	//’P€‰‰Zq- Vec2=-Vec2
	Vec2 operator - ()const
	{
		return Vec2{ -x,-y };
	}

	//‘«‚µZ
	Vec2 operator+(Vec2 vec) const
	{
		return Vec2{ x + vec.x,y + vec.y };
	}
	//Vec2 +=Vex2
	Vec2 operator+=(Vec2 vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	//ˆø‚«Z
	Vec2 operator-(Vec2 vec) const
	{
		return Vec2{ x - vec.x,y - vec.y };
	}
	//Vec2 +=Vex2
	Vec2 operator-=(Vec2 vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	////Š|‚¯Z
	//Vec2 mul(float scale)
	//{
	//	Vec2 result{ x * scale, y * scale };
	//	return result;
	//}

	//Š|‚¯Z
	Vec2 operator*(float scale) const
	{
		return Vec2{ x * scale, y * scale };
	}

	//Vec2 *=flaot 
	Vec2 operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	//Š„‚èZ
	Vec2 operator/(float scale) const
	{
		return Vec2{ x / scale, y / scale };
	}

	Vec2 operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	//fac *=frac
	/*Fration& Fractoin::operator*=(const Fraction)&rop
	{
		m_number *= rop.m_number;
		m_denom *= rop.m_denom;

	}*/

	//ƒxƒNƒgƒ‹‚Ì’·‚³‚Ì2æ‚ğ‹‚ß‚é
	float sqLength() const
	{
		return x * x + y * y;
	}
	//ƒxƒNƒgƒ‹‚Ì’·‚³‚ğ‹‚ß‚é
	float length() const
	{
		return sqrtf(sqLength());
	}

	//©g‚Ì³‹K‰»‚ğs‚¤
	void normalize()
	{
		float len = length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
		}
		//’·‚³‚O‚Ìê‡‚Í‰½‚à‚µ‚È‚¢
	}

	//©g‚ğ³‹K‰»‚µ‚½ƒxƒNƒgƒ‹‚ğæ“¾‚·‚é
	Vec2 getNormalize() const
	{
		float len = length();
		if (len > 0.0f)
		{
			return Vec2{ x / len, y / len };
		}
		//’·‚³‚ª0‚Ìê‡
		return Vec2{ 0.0f,0.0f };
	}
};


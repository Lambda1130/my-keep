#pragma once
#include"Vec2.h"

class Player
{
    //向いている方向
    enum Dir
    {
        kDirDown,
        kDirLeft,
        kDirRight,
        kDirUp
    };

public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

    //メンバー変数にアクセスする

    void SetHandle(int handle) { m_handle = handle; }

    Vec2 GetPos() const { return m_pos; }


private:

    int m_handle;    //グラフィックのハンドル
    //表示位置
    Vec2 m_pos;
    /* float m_posX;
     float m_posY;*/
     //向いている方向
    Dir m_dir;
    //歩きアニメーション
    int m_walkAnimFrame;
};


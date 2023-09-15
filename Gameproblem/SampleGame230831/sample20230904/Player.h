

#pragma once

class Player
{
public:
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


private:

    int m_handle;    //グラフィックのハンドル



    float m_posX;

    float m_posY;
    //向いている方向
    Dir m_dir;
    //歩きアニメーション
    int m_walkAnimFrame;
    
};

#pragma once
class EnemyRight
{
public:
    EnemyRight();
    ~EnemyRight();



    void Init();
    void Update();
    void Draw();



    //メンバー変数にアクセスする
    void SetHandle(int handle) { m_handle = handle; }



    bool isExist() const { return m_isExist; }



    //敵キャラクターをスタートさせる
    void start();



private:
    int m_handle;    //グラフィックのハンドル



    bool m_isExist;    //存在するかフラグ(使用中かどうか)



    float m_posX;
    float m_posY;



    int m_graphWidth;
    int m_graphHeight;



};


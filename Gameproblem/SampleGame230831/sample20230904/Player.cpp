#include "Player.h"
#include "DxLib.h"
#include "Game.h"



//Playerで使用する定数
namespace
{

    constexpr float kSpeed = 3.0f;

    //キャラクターサイズ
    constexpr int kWidth = 32;
    constexpr int kHeight = 32;

    //キャラクターのアニメーション
    constexpr int kUseFrame[] = { 0,1,2,1 };
    //プレイヤー1コマのフレーム数
    constexpr int kAnimFrameNum = 8;
    //アニメーション１サイクルのフレーム数
    constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimFrameNum;
}



Player::Player() :
    m_handle(-1),
    m_posX(Game::kScreenWidth / 2),
    m_posY(Game::kScreenHeight / 2),
    m_dir(kDirDown),
    m_walkAnimFrame(0)
{



}



Player::~Player()
{

}



void Player::Init()
{

}



void Player::Update()
{
    

    //padの十字キーを使用してプレイヤーを移動させる
    int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    bool isMove = false;


    /* (pad & PAD_INPUT_UP) == 0 の原理*/
    //0000 0000 0000 0000 0000 0000 0000 0000　基本
    //0000 0000 0000 0000 0000 0000 0000 1000　上キーが押されたとき



    if ((pad & PAD_INPUT_UP) != 0)
    {
        m_posY -= kSpeed;
        m_dir = kDirUp;
        isMove = true;
    }
    if ((pad & PAD_INPUT_DOWN) != 0)
    {
        m_posY += kSpeed;
        m_dir = kDirDown;
        isMove = true;
    }
    if ((pad & PAD_INPUT_LEFT) != 0)
    {
        m_posX -= kSpeed;
        m_dir = kDirLeft;
        isMove = true;
    }
    if ((pad & PAD_INPUT_RIGHT) != 0)
    {
        m_posX += kSpeed;
        m_dir = kDirRight;
        isMove = true;
    }
    if (isMove)
    {
         //歩きアニメーション
         m_walkAnimFrame++;
         if (m_walkAnimFrame >= kAnimFrameCycle) m_walkAnimFrame = 0;
    }
}



void Player::Draw()
{
 //   DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, true);
  //  DrawRectGraph(static_cast<int>(m_posX), static_cast<int>(m_posY),
  //      0, 0, 32, 32, m_handle, true);

    int animFrame = m_walkAnimFrame / kAnimFrameNum;

    int srcX = kUseFrame[animFrame] * kWidth;
    int srcY = kHeight*m_dir;
    /*
    switch (m_dir)
    {
    case kDirDown:
        srcY = 32*0;
        break;
    case kDirLeft:
        srcY = 32*1;
        break;
    case kDirRight:
        srcY = 32*2;
        break;
    case kDirUp:
        srcY = 32*3;
        break;
    }
    */
    DrawRectGraph(static_cast<int>(m_posX), static_cast<int>(m_posY),
        srcX, srcY, kWidth, kHeight, m_handle, true);
}

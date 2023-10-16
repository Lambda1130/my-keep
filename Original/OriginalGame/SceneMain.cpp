#include "SceneMain.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Player.h"

#include"Pad.h"


#include <cassert>

namespace
{
    constexpr int kEnemyMax = 64;

    constexpr int kEnemyInterval = 64;
}



SceneMain::SceneMain() 
{
    //グラフィックのロード
    m_playerHandle = LoadGraph("data/image/player.png");
    assert(m_playerHandle != -1);
   

    //プレイヤーのメモリ確保
    m_pPlayer = new Player;
    m_pPlayer->SetHandle(m_playerHandle);    //Playerにグラフィックハンドルを渡す

    
}

SceneMain::~SceneMain()
{
    //メモリからグラフィックを削除
    DeleteGraph(m_playerHandle);
   

    //プレイヤーのメモリ解放
    delete m_pPlayer;
    m_pPlayer = nullptr;

    
   

   
}



void SceneMain::Init()
{
    assert(m_pPlayer);    //m_pPlayer == nullptr の場合止まる



    m_pPlayer->Init();
    
}



void SceneMain::End()
{



}



void SceneMain::Update()
{
    m_pPlayer->Update();
   

    

    

   
  


    




}



void SceneMain::Draw()
{
   
    m_pPlayer->Draw();
   
    

   
    //Debag表示
    DrawString(8, 8, "SceneMain", GetColor(255, 255, 255));

    //プレイヤーの位置をデバッグ表示する
    Vec2 playerPos = m_pPlayer->GetPos();
    DrawFormatString(8, 24, GetColor(255, 255, 255),
        "プレイヤーの座標(%.2f, %.2f)", playerPos.x, playerPos.y);


}


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
    //�O���t�B�b�N�̃��[�h
    m_playerHandle = LoadGraph("data/image/player.png");
    assert(m_playerHandle != -1);
   

    //�v���C���[�̃������m��
    m_pPlayer = new Player;
    m_pPlayer->SetHandle(m_playerHandle);    //Player�ɃO���t�B�b�N�n���h����n��

    
}

SceneMain::~SceneMain()
{
    //����������O���t�B�b�N���폜
    DeleteGraph(m_playerHandle);
   

    //�v���C���[�̃��������
    delete m_pPlayer;
    m_pPlayer = nullptr;

    
   

   
}



void SceneMain::Init()
{
    assert(m_pPlayer);    //m_pPlayer == nullptr �̏ꍇ�~�܂�



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
   
    

   
    //Debag�\��
    DrawString(8, 8, "SceneMain", GetColor(255, 255, 255));

    //�v���C���[�̈ʒu���f�o�b�O�\������
    Vec2 playerPos = m_pPlayer->GetPos();
    DrawFormatString(8, 24, GetColor(255, 255, 255),
        "�v���C���[�̍��W(%.2f, %.2f)", playerPos.x, playerPos.y);


}


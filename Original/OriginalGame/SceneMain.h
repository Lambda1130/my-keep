#pragma once
#pragma once
class Player;


class SceneMain
{
public:
    SceneMain();
    ~SceneMain();



    void Init();
    void End();
    void Update();
    void Draw();






private:
    //�O���t�B�b�N�̃n���h��
    int m_playerHandle;
    ;


    //�v���C���[
    Player* m_pPlayer;



   
   

   
   
};


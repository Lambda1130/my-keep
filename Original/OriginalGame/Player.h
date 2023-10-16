#pragma once
#include"Vec2.h"

class Player
{
    //�����Ă������
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

    //�����o�[�ϐ��ɃA�N�Z�X����

    void SetHandle(int handle) { m_handle = handle; }

    Vec2 GetPos() const { return m_pos; }


private:

    int m_handle;    //�O���t�B�b�N�̃n���h��
    //�\���ʒu
    Vec2 m_pos;
    /* float m_posX;
     float m_posY;*/
     //�����Ă������
    Dir m_dir;
    //�����A�j���[�V����
    int m_walkAnimFrame;
};


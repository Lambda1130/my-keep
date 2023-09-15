#pragma once

class Player
{
public:
	Player();  //�������ɌĂ΂��
	~Player(); //�������ɌĂ΂��

	void init();   
	void update();
	void draw()const;

	//�������֐��̓x�b�^�[�ɒ��g���������Ƃ�����
	//set get �֐��̓N���X�������Ă���Ƃ悭�o�Ă���̂Ŋo���悤
	//get�֐���const�ɂ��Ă��N�Z�����悤
	void setPosX(int x) { m_posX = x; }
	int getPosX()const { return m_posX; }
	int getPosY()const { return m_posY; }

	//���a�̎擾
	int getRadius()const;

	//�����o�[�ϐ���private
private:
	int m_posX;
	int m_posY;
};


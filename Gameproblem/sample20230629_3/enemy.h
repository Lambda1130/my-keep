#pragma once

//�N���X�̐錾
class Enemy
{
public:
	Enemy();
	~Enemy();

	void init();
	void update();
	void draw();

	//�����o�[�ϐ��𒼐ڕύX�������ꍇ��
	//public�ȃ����o�֐����o�R���ĕύX����
	//�s���Ȓl��ݒ肳�ꂽ�ꍇ�A�s������Ȃ��悤�ɂ�����ł���
	void setPosX(int x);
	int getPosX(){ return m_posX; }
	int getPosY(){ return m_posY; }

	void kDefaultColor();
	void redColor();

	int getRadius();
	//���a�̎擾

	//�����o�[�ϐ���private
private:
	int m_posX;
	int m_posY;
	


};

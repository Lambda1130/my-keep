#pragma once

class Cirle
{
public:
	Cirle();  //�R���X�g���N�^�@���������m�ۂ��ꂽ�Ƃ������I�ɌĂ΂��֐�
	~Cirle(); //�f�X�g���N�^�@����������������Ƃ��Ɏ����I�ɌĂ΂��

	void init();
	void update();
	void draw();

	//�����o�ϐ��̒l���擾�������ꍇ��public�͊֐��o�R�ōs��
	bool isExit() { return m_isExist; }

	//�~�̃T�C�Y������������
	void smaller(int size);

	//set,get�֐��͒��
	int getPosX() { return m_posX; }
	void setPosX(int x) { m_posX = x; }

	//�����o�ϐ��͕K��private�ɂ���
private:
	int m_posX;
	int m_posY;
	
	//���a
	int m_radius;

	//
	bool m_isLasMouseDown;

	//�}�E�X�J�[�\�����~�̒��ɂ��邩
	bool m_isMouseIn;

	//���̉~�����݂��Ă��邩
	bool m_isExist;
};
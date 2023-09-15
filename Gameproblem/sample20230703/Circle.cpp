#include"Circleh.h"
#include"DxLib.h"
#include<cmath>

namespace
{
	//�~�̏��������a
	constexpr int kRadiusDefault = 64;
	//�ŏ��T�C�Y
	constexpr int kRadiusMin = 12;
}

Cirle::Cirle():
	m_posX(0),
	m_posY(0),
	m_radius(64),
	m_isLasMouseDown(true),
	m_isMouseIn(false),
	m_isExist(true)
{

	//rand()�̎��Ǝg�������肪�Ⴄ�̂ŋC��t����
//	int num = rand() % 64;  //0~63
//	int num2 = GetRand(64);
}

Cirle::~Cirle()
{

}

void Cirle::init()
{
	m_posX=GetRand(640 - m_radius * 2) + m_radius;
	m_posY=GetRand(480 - m_radius * 2) + m_radius;
	m_isExist = true;
}

void Cirle::update()
{
	//�}�E�X���N���b�N����Ă����Ԃ��擾
	bool isClick = false;
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) !=0)
	{
		isClick = true;
	}

	if (!m_isExist)
	{
		m_isLasMouseDown = isClick;
		return;
	}
	//�}�E�X�J�[�\���ʒu�擾
	int mouseX;
	int mouseY;
	GetMousePoint(&mouseX, &mouseY);

	//(float)num :C���ꕗ�L���X�g�@c++�ł͎g��Ȃ�
	//static_cast<float>(num) :C++�̃L���X�g static_�ȊO�̃L���X�g�����邪����͂�������
	float dx =static_cast<float>(mouseX - m_posX);
	float dy =static_cast<float>(mouseY - m_posY);

	if (sqrtf(dx * dx + dy * dy)<m_radius)
	{
		//�}�E�X�J�[�\�����~�̒��ɂ���
		m_isMouseIn = true;
	}
	else
	{
		m_isMouseIn = false;
	}

	//�N���b�N��������
	if (isClick && !m_isLasMouseDown)
	{
		if(m_isMouseIn)   //�J�[�\�����~�̒��ɂ����ԂŃN���b�N����
		{
			//�~������
			m_isExist = false;
		}
		
	}
	//
	m_isLasMouseDown=isClick;
}

void Cirle::draw()
{
	if (!m_isExist)  return;

	unsigned int color=GetColor(255,255,255);
	if (m_isMouseIn)
	{
		color = GetColor(255, 255, 0);
	}
		DrawCircle(m_posX, m_posY, m_radius,color, true);

		//
		DrawFormatString(0, 0, GetColor(255, 255, 255),
			"pos(%d,%d)", m_posX, m_posY);
}

void Cirle::smaller(int size)
{
	m_radius -= size;
	//�T�C�Y�̉�����ݒ肷��
	if (m_radius < kRadiusMin)
	{
		m_radius = kRadiusMin;
	}
}
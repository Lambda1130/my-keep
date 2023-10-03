#pragma once
#include<iostream>
using namespace std;

//�����X�^�[�̊��N���X
class EnemyBase
{
public:
	EnemyBase(){}
	~EnemyBase() { cout << "Base" << endl; }

	//�㏑���ioverraide�j�������֐��̓���
	//virtual������

	//EnemyBase�Ƃ���Enemy�𐶐����邱�Ƃ͂Ȃ�
	//�Ȃ̂�GetName()�͕K���㏑�����Ăق���
	//��΂ɏ㏑�����Ăق����֐��́w�������z�֐��x�ɂ���
	//�������z�֐��͊֐��Ɂ��O�Ƃ���
	virtual const char* GetName() = 0;
//	virtual const char* GetName() { return "�ȂȂ�"; }

protected:
	int m_hp = 0; //����ȏ��������\

};

//�X���C��
class EnemySlime : public EnemyBase
{
public:
	EnemySlime(){}
	virtual ~EnemySlime() { cout << "Slime" << endl; }
	//�X���C�����p�����ăX���C���x�X�����w�\��������x
	//�̂ňꉞvirtual�ɂ��Ă���
	virtual const char* GetName() override { return "�X���C��"; }
};

//�h���S��
class EnemyDorakey : public EnemyBase
{
public:
	EnemyDorakey() {}
	~EnemyDorakey() {}

	virtual const char* GetName() override { return "�h���L�["; }
};

//�h���S��
class EnemyDoragon : public EnemyBase
{
public:
	EnemyDoragon(){}
	~EnemyDoragon(){}

	virtual const char* GetName() override { return "�h���S��"; }
};
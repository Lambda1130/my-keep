#pragma once
#include<iostream>
using namespace std;

//���p���Ƃ́H
//����N���X��ɐV�����N���X����邱�Ƃ��ł���
//������p���Ƃ���

//�����ClassBase����ɐV�����N���X���쐬����
//��ɂȂ�N���X�̂��Ƃ����N���X�ƌĂ�
class ClassBase
{
public:
	ClassBase() :
		m_num(0)
	{
		//���N���X�̃R���X�g���N�^�𖾎��I�ɌĂ΂Ȃ��ꍇ
		//�p����̃N���X�̃R���X�g���N�^�Ăяo���O��
		//���������̌p�����̃R���X�g���N�^���Ăяo�����

		cout << "ClassChild�̃R���X�g���N�^" << m_num << endl;
	}

	ClassBase(int num):
		m_num(num)
	{
		cout << "ClassBase�̃R���X�g���N�^" <<m_num<< endl;
	}

	~ClassBase()
	{
		cout << "ClassBase�̃f�X�g���N�^" <<m_num<< endl;
	}

	void Func0()
	{
		cout << "ClassBase::Func0" <<m_num<< endl;
	}
	void Func1()
	{
		cout << "ClassBase::Func1" << m_num << endl;
	}
	void Func2()
	{
		cout << "ClassBase::Func2" << m_num << endl;
	}

	//private�ȃ����o�[�̓N���X�O����Q�Ƃł��Ȃ�
	//����͌p����̃N���X�ł����l
	//�p����̃N���X��a���N���X�̎��ϐ���ύX�������ꍇ�͂悭����
private:
	//�ʒu����U���͂ȂǁA���N���X�Ɏ�������
	//�p����ł��ύX���s�������ϐ��͂�����ł�����
	
	//���������ꍇ��protected�Ő錾����
	//protected�ȏꍇ�A�֐��̓N���X�O����͌����Ȃ����A
	//�p����̃N���X����͌��邱�Ƃ��ł���

	//�悭�킩��Ȃ��Ԃ͊��N���X�̃����o�ϐ���
	//���ׂ�protected�ł����Ǝv��
protected:

	void ProtectedFunc()
	{
		cout << "protected�Ȋ֐�" << endl;
	}

	int m_num;
};

//ClassBase����ɐV�����N���X���쐬����
//ClassBase���p�����ĐV�����N���X���쐬����

//�N���X�̐錾���Ɍp�����ƂȂ�N���X���w�肷��K�v������
class ClassChikd0 : public ClassBase
{
public:
	ClassChikd0()
	{
		cout << "ClassChild0�̃R���X�g���N�^"<< endl;
	}
	ClassChikd0(int num) :
		ClassBase(num)  //�p����N���X�̃R���X�g���N�^�𖾎��I�ɌĂ�
	{
		cout << "ClassChild0�̈����t���̃R���X�g���N�^" << endl;
	}

	~ClassChikd0()
	{
		cout << "ClassChild0�̃f�X�g���N�^" << endl;

		//�p����̃f�X�g���N�^���Ă΂ꂽ��.
		//�p�����̃f�X�g���N�^���Ă΂��
	}
};

//������ClassBase���p�������N���X
class ClassChild1 :public ClassBase
{
public:
	ClassChild1()
	{
		cout << "ClassChild1�̃R���X�g���N�^" << endl;
	}
	~ClassChild1()
	{
		cout << "ClassChild1�̃f�X�g���N�^" << endl;
	}

	//���N���X��Func0���g���̂ł͂Ȃ�
	//���̃N���X�̓���ȏ������s������
	void Func0()
	{
		cout << "ClassChild1�̓����Func0" << endl;

		//proteced�ȕϐ��A�֐��͌p���悩��Ăяo�����Ƃ��ł���
		m_num = 999;
		ProtectedFunc();
	}

};
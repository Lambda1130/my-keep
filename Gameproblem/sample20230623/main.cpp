#include<iostream>
using namespace std;

void printMsg(void)
{
	cout << "test" << endl;
}

//NG �߂�l���Ⴄ�����̓����֐��͍쐬�ł��Ȃ�

//void printMsg(void)
//{
//	cout << "test2" << endl;
//	return 10;
//}


//void printMsg(int score=50)   //ng �������ȗ������ꍇ�A�����Ȃ��ƌ����������Ȃ��̂�ng
void printMsg(int num, int score=50)
{
	cout << "�e�X�g�_:" <<score<< endl;
}

//void printMsg(int num)  //ng �����Q��2�ڂ��f�t�H���g�����A�ƌ����������Ȃ��̂�Ng
//{
//	cout << "num:" << num << endl;
//}

//c++�ł͊֐��̈����Ƀf�t�H���g�̒l��ݒ�ł���
struct Player
{
	int hp;
	int mp;
};

//�������̌�Ɂ��T�O�̂悤�ɏȗ������ꍇ�ɐݒ肳��鐔�l���w��ł���
// ������f�t�H���g�����Ƃ���
// �f�t�H���g�������ݒ肳��Ă���ꍇ�A�����ȗ����邱�Ƃ��ł���
//�ȗ������ꍇ�A�������ɂ͐ݒ肵���l������
void initPlayer(Player& player, int hp=100, int mp=50)
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{
	printMsg();
	printMsg(10);
	printMsg(10,50);


	Player player;
	initPlayer(player);

	//�L�����N�^�[�I���\
	//�P�O�O��ރL�����N�^�[������
	//1�̗͎̂͑���      hp200, mp0
	//1�͖̂��@�g��      hp50,  mp100
	//����ȊO�̂X�W�̂� hp100, mp50

	cout << "HP:" << player.hp << endl;
	cout << "MP:" << player.mp << endl;

	return 0;
}
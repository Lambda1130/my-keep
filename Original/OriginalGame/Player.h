#pragma once
class Player
{
public:
	Player();
	~Player();

	void All();

private:
	void Init();
	void Updata();
	void Draw();

private:
	//x���W,y���W 
	double x, y;

	//�摜��
	int width, height;

	//�O���t�B�b�N�n���h���i�[�p�z��
	int gh[12];

	//�ړ��W��
	float move;

	//�������Əc�����̃J�E���g��
	int Xcount, Ycount;
	//�Y���p�ϐ�
	int Ix, Iy, result;
	//�����Ă��邩�̃t���O
	bool life;
	
};


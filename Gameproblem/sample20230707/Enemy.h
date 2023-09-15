#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw()const;

	void SetGraphHandle(int handle);

	//�G�L�����N�^�[�J�n����
	//��ʏォ�痎���n�߂�
	void Start();

	//���݂��邩�`�F�b�N
	bool isExist() const { return m_isExist; }

	//�Z�`�̓����蔻����Ƃ�̂ɕK�v�ȏ����擾����
	float GetLeft()const; //����X���W
	float GetTop()const; //���Y���W
	float GetRight()const; //�E��X���W
	float GetBottom()const; //����Y���W


	//�G�L�����N�^�[�̏����ʒu(�O���t�B�b�N��ݒ肵�Ă���s��)
	void SetStartPos();

private:
	static constexpr int kPosLogFrame = 8;

private:
	int m_handle;
	int m_width;
	int m_height;


	bool m_isExist;

	float m_posX[kPosLogFrame];
	float m_posY[kPosLogFrame];

	//�ړ���
	float m_moveY;
};


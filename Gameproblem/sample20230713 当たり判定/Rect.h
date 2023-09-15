#pragma once
class Rect
{
public:
	Rect();
	~Rect();

	void Init();
	void Update();
	void Draw();

	//��ʓ��̃����_���Ȉʒu�Ƀ����_���ȑ傫���̋�`�f�[�^��ݒ肷��
	void SetRandom();

	//���̋�`�Ƃ̓����蔻��
	//���g�Ǝw�肵�����̋�`�̓����蔻������
	bool IsCollision(const Rect& target)const;

	//public�Ȋ֐��o�R�Ń����o�[�ϐ���ύX
	void SetColor(unsigned int color) { m_color = color; }
	void SetFill(bool isFill) { m_isFill = isFill; }
	void SetMouseTrase(bool isTrase) { m_isMoreTrase = isTrase; }

//	void setPosX(int x) { m_posX = x; }
//	void setPosX(int y) { m_posX = y; }

	//�����蔻������p�ɏ㉺���E�̍��W���擾�ł���悤�ɂ���
	int GetLeft()const;
	int GetTop()const;
	int GetRight()const;
	int GetBottom()const;

private:
	//���S���W�ƕ��A�����ŊǗ�����
	int m_posX;  //m_center�݂����Ȃ��̗ǂ�����
	int m_posY;
	int m_width;
	int m_height;

	//�F
	unsigned int m_color;
	//�h��Ԃ��t���O
	bool m_isFill;

	//�}�E�X�Ǐ]�t���O
	bool m_isMoreTrase;
};


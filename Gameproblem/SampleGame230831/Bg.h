#pragma once
class Bg
{
public:
	Bg();
	~Bg();

	void Init();
	void Update();
	void Draw();

	//�O���t�B�b�N�̐ݒ�
	void SetHandle(int handle) { m_handle = handle; }

private:
	int m_handle;

	//�O���t�B�b�N�Ɋ܂܂��}�b�v�`�b�v�̐�
	int m_graphChipNumX;
	int m_graphChipNumY;
};


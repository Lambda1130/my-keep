#pragma once
class SceneTitle
{
public:
	SceneTitle();
	~SceneTitle();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	static constexpr int KBgNum = 4;

private:
	int m_bgHandle[KBgNum];   //bg=background
	int m_bgNo;

	int m_fadeCount;   //�t�F�[�h�x���� 0:�s�����A�t�F�[�h�C�������������(�Q�[����ʂ������Ă���)
	                   //               255:�s�����A�t�F�[�h�A�E�g�����������
	int m_fadeSpeed;   //���x 
	int m_waitFrame;   // �t�F�[�h�C������������̑҂�����
};


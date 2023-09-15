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

	int m_fadeCount;   //フェード度合い 0:不透明、フェードインしきった状態(ゲーム画面が見えている)
	                   //               255:不透明、フェードアウトしきった状態
	int m_fadeSpeed;   //速度 
	int m_waitFrame;   // フェードインしきった後の待ち時間
};


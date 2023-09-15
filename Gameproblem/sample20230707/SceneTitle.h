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

	bool IsSceneEnd() const;

private:
	bool m_isSceneEnd;  //シーン終了フラグ
	               //true: タイトルを終了してゲームへ

	//BGM
	int m_bgmHandle;

	//効果音のハンドル
	int m_decideSe;

	//フェードイン、アウト
	int m_fadeAlpha;
};


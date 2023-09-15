#pragma once
class SceneResult
{
public:
	SceneResult();
	~SceneResult();

	void Init();
	void Update();
	void Draw();
	void End();

	bool IsSceneEnd() const { return m_isSceneEnd; }

private:

	int m_gameoverHandle;

	int m_bgmHandle;

	bool m_isSceneEnd;

};


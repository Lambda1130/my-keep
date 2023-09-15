#pragma once
class EnemyRight
{
public:
	EnemyRight();
	~EnemyRight();

	void Init();
	void Update();
	void Draw() const;

	// メンバー変数にアクセスする
	void SetHandle(int handle) { m_handle = handle; }

	bool IsExist() const { return m_isExist; }

	// 敵キャラクターをスタートさせる
	void Start();

private:
	int m_handle;	// グラフィックのハンドル
	int m_graphWidht;
	int m_graphHeight;

	bool m_isExist;	// 存在しているかフラグ(使用中かどうか)

	float m_posX;
	float m_posY;
};


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

	//敵キャラクター開始処理
	//画面上から落ち始める
	void Start();

	//存在するかチェック
	bool isExist() const { return m_isExist; }

	//短形の当たり判定をとるのに必要な情報を取得する
	float GetLeft()const; //左のX座標
	float GetTop()const; //上のY座標
	float GetRight()const; //右のX座標
	float GetBottom()const; //下のY座標


	//敵キャラクターの初期位置(グラフィックを設定してから行う)
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

	//移動量
	float m_moveY;
};


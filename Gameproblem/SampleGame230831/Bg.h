#pragma once
class Bg
{
public:
	Bg();
	~Bg();

	void Init();
	void Update();
	void Draw();

	//グラフィックの設定
	void SetHandle(int handle) { m_handle = handle; }

private:
	int m_handle;

	//グラフィックに含まれるマップチップの数
	int m_graphChipNumX;
	int m_graphChipNumY;
};


#pragma once
class Player
{
public:
	Player();
	~Player();

	void All();

private:
	void Init();
	void Updata();
	void Draw();

private:
	//x座標,y座標 
	double x, y;

	//画像幅
	int width, height;

	//グラフィックハンドル格納用配列
	int gh[12];

	//移動係数
	float move;

	//横方向と縦方向のカウント数
	int Xcount, Ycount;
	//添字用変数
	int Ix, Iy, result;
	//生きているかのフラグ
	bool life;
	
};


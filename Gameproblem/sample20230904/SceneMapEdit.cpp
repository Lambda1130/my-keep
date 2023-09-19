#include "SceneMapEdit.h"
#include"DxLib.h"
#include <cassert>

#include"Pad.h"

//ファイルの出力に使用する
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

namespace
{
	constexpr int kCursorRepeatFrame = 4;
}

SceneMapEdit::SceneMapEdit():
	m_cursorX(0),
	m_cursorY(0),
	m_rightRepeatFrame(0),
	m_leftRepeatFrame(0),
	m_upRepeatFrame(0),
	m_downRepeatFrame(0)
{
	//グラフィックのロード
	m_bgHandle = LoadGraph("data/image/bg.png");
	assert(m_bgHandle != -1);

	//マップチップの数を数える
	int graphW = 0;
	int graphH = 0;
	GetGraphSize(m_bgHandle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipWidth;
	m_graphChipNumY = graphH / kChipHeight;

	//チップの配置情報
	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
			m_chipData[y][x] = 0;
		}

	}
	
}

SceneMapEdit::~SceneMapEdit()
{
	//グラフィックの解放

}

void SceneMapEdit::Init()
{
}

void SceneMapEdit::End()
{
}

void SceneMapEdit::Update()
{
	//カーソルの移動
//	if ((pad & PAD_INPUT_UP) != 0)

	if (Pad::IsPress(PAD_INPUT_UP))
	{
		m_upRepeatFrame++;
		if (m_upRepeatFrame >= kCursorRepeatFrame)
		{
			m_upRepeatFrame = 0;

			//カーソルの移動処理
			CursorUp(Pad::IsTrigger(PAD_INPUT_UP));
		}
	}

	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		m_downRepeatFrame++;
		if (m_downRepeatFrame >= kCursorRepeatFrame)
		{
			m_downRepeatFrame = 0;
			CursorDown(Pad::IsTrigger(PAD_INPUT_DOWN));
		}

	}

	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		m_leftRepeatFrame++;
		if (m_leftRepeatFrame >= kCursorRepeatFrame)
		{
			m_leftRepeatFrame = 0;
			CursorLeft(Pad::IsTrigger(PAD_INPUT_LEFT));

		}
	}

	//右方向へのカーソル移動
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		m_rightRepeatFrame++;
		if (m_rightRepeatFrame >= kCursorRepeatFrame)
		{
			m_rightRepeatFrame = 0;

			//カーソル移動処理
			CursorRight(Pad::IsTrigger(PAD_INPUT_RIGHT));
		}
	}
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		assert(m_cursorX >= 0 && m_cursorX < kChipNumX);
		assert(m_cursorY >= 0 && m_cursorX < kChipNumX);

		//選択しているマップチップ番号を+1
		m_chipData[m_cursorY][m_cursorX]++;

		//グラフィック内に存在するマップチップの数
		int chipNum = GetGraphChipNum();

	
		//ループ処理
		if (m_chipData[m_cursorY][m_cursorX] > chipNum-1)
		{
			m_chipData[m_cursorY][m_cursorX] = 0;
		}

	}
	if (Pad::IsTrigger(PAD_INPUT_2))
	{
		assert(m_cursorX >= 0 && m_cursorY < kChipNumY);
		assert(m_cursorY >= 0 && m_cursorY < kChipNumY);

		//選択しているマップチップ番号を-1
		m_chipData[m_cursorY][m_cursorX]--;

		//グラフィック内に存在するマップチップの数
		int chipNum = GetGraphChipNum();

		//ループ処理
		if (m_chipData[m_cursorY][m_cursorX] < 0)
		{
			m_chipData[m_cursorY][m_cursorX] = chipNum - 1;
		}
	}

	//ファイル出力テスト
	if (Pad::IsTrigger(PAD_INPUT_3))  
	{
		fstream file;

		file.open("test.txt",ios::out);  //ファイルを開く 
	
		//ファイルを開くのに失敗した場合の処理
		if (!file.is_open())
		{
			//ファイルが開けなかった場合の処理
			// return EXIT_FAILURE; //教科書は開けなかったらその時点でプログラム終了
			printfDx("ファイルを開くのに失敗しました。\n");
		}
		else
		{
			//ファイルが開けた場合の処理
			file << "ファイルに書き込んじゃえ。" << endl;

			//数値の書き込みテスト
			int num = 100;
			file << num << endl;
			file.close();

			printfDx("ファイルに書き込みを行いました。\n");
		}
	}

	//ファイル読み込みテスト
	if (Pad::IsTrigger(PAD_INPUT_4))
	{

	}
}

void SceneMapEdit::Draw()
{
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			//マップ情報から置くチップをとってくる
			int chipNo = m_chipData[y][x];

			//マップチップのグラフィック切り出し座標
			int srcX = kChipWidth * (chipNo % m_graphChipNumX);
			int srcY = kChipHeight * (chipNo / m_graphChipNumX);


			DrawRectGraph(x * kChipWidth, y * kChipHeight, srcX, srcY, kChipWidth, kChipHeight, m_bgHandle, true);
		}

	}

	//グリットの表示

	//縦線
	for (int x = 0; x < kChipNumX; x++)
	{
		DrawLine(x * kChipWidth, 0, x * kChipWidth, Game::kScreenHeight,GetColor(255,255,255));
	}
	//横線
	for (int y = 0; y < kChipNumY; y++)
	{
		DrawLine(0,y * kChipHeight, Game::kScreenWidth,y* kChipHeight, GetColor(255, 255, 255));
	}


	//現在選択しているチップにカーソルを表示
	int cursorPosX = m_cursorX * kChipWidth;
	int cursorPosY = m_cursorY * kChipHeight;
	DrawBox(cursorPosX, cursorPosY,    //左上座標 
		cursorPosX + kChipWidth, cursorPosY + kChipHeight,  //右下座標 
		GetColor(255, 0, 0), false);
	DrawBox(cursorPosX+1, cursorPosY+1,    //左上座標 
		cursorPosX + kChipWidth-1, cursorPosY + kChipHeight-1,  //右下座標 
		GetColor(255, 0, 0), false);
}

void SceneMapEdit::CursorUp(bool isLoop)
{
	m_cursorY--;
	if (m_cursorY < 0)
	{
		if (isLoop)
		{
			m_cursorY = kChipNumY - 1;
		}
		else
		{
			m_cursorY = 0;
		}
	}
}

void SceneMapEdit::CursorDown(bool isLoop)
{
	m_cursorY++;
	if (kChipNumY - 1 < m_cursorY)
	{
		if (isLoop)
		{
			m_cursorY = 0;
		}
		else
		{
			m_cursorY = kChipNumY - 1;
		}
	}
}

void SceneMapEdit::CursorRight(bool isLoop)
{
	m_cursorX++;
	if (kChipNumX - 1 < m_cursorX)
	{
		if (isLoop)
		{
			m_cursorX = 0;
		}
		else
		{
			m_cursorX = kChipNumX - 1;
		}
	}
}

int SceneMapEdit::GetGraphChipNum()
{
	return m_graphChipNumX * m_graphChipNumY;;
}

void SceneMapEdit::CursorLeft(bool isLoop)
{
	m_cursorX--;
	if (m_cursorX < 0)
	{
		if (isLoop)
		{
			m_cursorX = kChipNumX - 1;
		}
		else
		{
			m_cursorX = 0;
		}
	}
}

void SceneMapEdit::OutputBinary()
{
	std::fstream file;



	// バイナリモードで開く
	// 拡張子はなんでもよい　バイナリデータを表すbin, データを表すdat等がメジャー
	file.open("map.bin", std::ios::out | std::ios::binary);



	if (!file.is_open())
	{
		printfDx("ファイルを開くのに失敗しました\n");
	}
	else
	{
		// マップチップの配置データをバイナリで出力

		// fstreamのwrite関数を使用して出力する
		// メモリ上のどこに置かているか(アドレス)と
		// そこから何バイト出力するか、を指定する
		file.write((const char*)&m_chipData, sizeof(m_chipData));



		file.close();



		printfDx("バイナリデータとしてマップデータを出力しました\n");
	}
}



void SceneMapEdit::InputBinary()
{
	std::fstream file;



	// バイナリモードで開く
	file.open("map.bin", std::ios::in | std::ios::binary);



	if (!file.is_open())
	{
		printfDx("ファイルを開くのに失敗しました\n");
	}
	else
	{
		// 読み込んだバイナリの内容をメモリ上のマップチップ情報に上書きする
		file.read((char*)&m_chipData, sizeof(m_chipData));



		file.close();



		printfDx("バイナリデータとしてマップデータを入力しました\n");
	}
}

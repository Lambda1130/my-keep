#include "SceneMapEdit.h"
#include "DxLib.h"
#include <cassert>
#include "Pad.h"

namespace
{
	//カーソル移動リピートフレーム
	constexpr int kCursorRepeatFrame = 4;
}

SceneMapEdit::SceneMapEdit() :
	m_cursorX(0),
	m_cursorY(0),
	m_upRepeatFrame(0),
	m_downRepeatFrame(0),
	m_leftRepeatFrame(0),
	m_rightRepeatFrame(0)
{
	//グラフィックのロード
	m_bgHandle = LoadGraph("data/image/bg.png");
	assert(m_bgHandle != -1);

	//マップチップの数を数える
	int graphW = 0;
	int graphH = 0;
	GetGraphSize(m_bgHandle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipHeight;
	m_graphChipNumY = graphH / kChipHeight;

	//チップ配置情報の生成
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
	// パッドの十字キーを使用してプレイヤーを移動させる
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		m_upRepeatFrame++;
		if ((m_upRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_UP))
		{
			m_upRepeatFrame = 0;

			//カーソルの移動処理
			CursorUp(Pad::IsTrigger(PAD_INPUT_UP));
		}


	}
	if (Pad ::IsPress(PAD_INPUT_DOWN))
	{
		m_downRepeatFrame++;
		if ((m_downRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_DOWN))
		{
			m_downRepeatFrame = 0;
			//カーソルの移動処理
			CursorDown(Pad::IsTrigger(PAD_INPUT_DOWN));
		}
	}
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		m_leftRepeatFrame++;
		if ((m_leftRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_LEFT))
		{
			m_leftRepeatFrame = 0;

			//カーソルの移動処理
			CursorLeft(Pad::IsTrigger(PAD_INPUT_LEFT));
		}
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		m_rightRepeatFrame++;
		if( (m_rightRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_RIGHT))
		{
			m_rightRepeatFrame = 0;

			//カーソルの移動処理
			CursorRight(Pad::IsTrigger(PAD_INPUT_RIGHT));
		}
	}
	if (Pad::IsPress(PAD_INPUT_1))
	{



	}
	if (Pad::IsPress(PAD_INPUT_2))
	{



	}
}



void SceneMapEdit::Draw()
{
	//	DrawGraph(0, 0, m_handle, true);

	clsDx();
	printfDx("m_cursorX : %d\n", m_cursorX);
	printfDx("m_cursorY : %d\n", m_cursorY);

	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
			//マップ情報から置くチップをとってくる
			int chipNo = m_chipData[y][x];

			//マップチップのグラフィック切り出し座標
			int srcX = kChipWidth * (chipNo / m_graphChipNumX);
			int srcY = kChipHeight * (chipNo / m_graphChipNumY);

			DrawRectGraph(x * kChipWidth, y * kChipHeight,
				srcX, srcY, kChipWidth, kChipHeight,
				m_bgHandle, true);
		}

		//現在選択している　チップにカーソルを表示
		int cursorPosX = m_cursorX * kChipWidth;
		int cursorPosY = m_cursorY * kChipHeight;
		DrawBox(cursorPosX, cursorPosY, cursorPosX + kChipWidth, cursorPosY + kChipHeight,//左上座標
			GetColor(255, 0, 0), false); //右下座標
		//一回り小さい資格を描写して線の太い四角にする
		DrawBox(cursorPosX + 1, cursorPosY + 1, cursorPosX + kChipWidth - 1, cursorPosY + kChipHeight - 1,
			GetColor(255, 0, 0), false);

	}
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
	if (m_cursorY > kChipNumY-1)
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

void SceneMapEdit::CursorRight(bool isLoop)
{
	m_cursorX++;
	if (m_cursorX > kChipNumX-1)
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


#include "Bg.h"
#include "DxLib.h"
#include "Game.h"

namespace
{
	//�}�b�v�`�b�v�̏��
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	//�`�b�v��u����
	constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	constexpr int kChipNumY = Game::kScreenWidth / kChipHeight;

	//�}�b�v�`�b�v�̔z�u���
	constexpr int kChipData[kChipNumY][kChipNumX] =
	{
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{ 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

}

Bg::Bg():
	m_handle(-1),
	m_graphChipNumX(0),
	m_graphChipNumY(0)
{
	
}

Bg::~Bg()
{
}

void Bg::Init()
{
	//�}�b�v�`�b�v�̐��𐔂���
	int graphW = 0;
	int graphH = 0;
	GetGraphSize(m_handle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipHeight;
	m_graphChipNumY = graphH / kChipHeight;

	//�f�o�b�O�\��
//	printfDx("ChipNumX:%d\n", m_graphChipNumX);
//	printfDx("ChipNumY:%d\n", m_graphChipNumY);


}

void Bg::Update()
{
}

void Bg::Draw()
{

//	DrawGraph(0, 0, m_handle, true);

	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
	int chipNo = 48;
	
	//�}�b�v�`�b�v�̃O���t�B�b�N�؂�o�����W
	int srcX = kChipWidth * (chipNo / m_graphChipNumX);
	int srcY = kChipHeight * (chipNo / m_graphChipNumY);

			DrawRectGraph(x * kChipWidth, y * kChipHeight,
				srcX, srcY, kChipWidth, kChipHeight,
				m_handle, true);
		}
	}

}

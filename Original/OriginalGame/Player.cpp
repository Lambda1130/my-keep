#include "Player.h"
#include"DxLib.h"

Player::Player()
{
	//画像読み込み
	if (-1 == LoadDivGraph("data/player.png", 12, 3, 4, 29, 40, gh))
	{
	}
}

Player::~Player()
{
}

void Player::All()
{
}

void Player::Init()
{
}

void Player::Updata()
{
}

void Player::Draw()
{
}

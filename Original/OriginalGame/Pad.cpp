#include "Pad.h"
#include"DxLib.h"

namespace
{
	//�O�̃t���[���̃p�b�h�����������
	int lastPad = 0;
	//���̃t���[���̃p�b�h�����������
	int nowPad = 0;
}

namespace Pad
{
	void Update()
	{
		//�O�̃t���[���Ɏ擾�����p�b�h������Â����ɂ���
		lastPad = nowPad;
		//���݂̃p�b�h�̏����擾����
		nowPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}
	bool IsPress(int key)
	{
		return (nowPad & key);
	}
	bool IsTrigger(int key)
	{
		bool isNow = (nowPad & key);  //���̃t���[��
		bool isLast = (lastPad & key);  //���̃t���[��
		return !isLast && isNow;
	}
	bool IsRelase(int key)
	{
		bool isNow = (nowPad & key);  //���̃t���[��
		bool isLast = (lastPad & key);  //���̃t���[��
		return isLast && !isNow;
	}
}
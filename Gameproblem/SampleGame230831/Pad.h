#pragma once

//�p�b�h�̏�Ԃ��擾����
namespace Pad
{
	//�p�b�h�̍X�V�����@1�t���[���Ɉ��s��
	void Update();

	//������Ă��邩���擾
	bool IsPress(int Key);
	//�����ꂽ�u�Ԃ��擾
	bool IsTrigger(int Key);
	//�b�����u�Ԃ��擾
	bool IsRelase(int Key);
}
#include<iostream>
using namespace std;

//c++�s�萔��`
//const int kArraySize = 5;

//����Ic++�̒萔��`
namespace
{
	constexpr int kConstextprNum = 3;   //constexpr:�萔���`���邽�߂ɏ������ꂽ������
                                     	//�R���p�C�����_�Œl�����܂��Ă���ꍇ�͂�����
	const int kConstNum = 3;            //const:�ϐ��̕ύX��s�\�ɂ��邽�߂̏�����
                                       	//�ŏ��Ɍ��߂��l����ύX�ł��Ȃ��Ƃ��������𗘗p����
}                                       //�萔��`�Ɏg�p��������

//�萔��`�̂܂Ƃ�
//namespace(�������O��ԁ@���O���ݒ肳��Ă��Ȃ�namespace)�̒��ɓ����
//�������O��Ԃ̒��ɏ����Ă���ϐ���萔�A�֐��͂��̃\�[�X�R�[�h�ł̂ݗL��
namespace
{
	//��{�I�ɓG����constexpr�Œ�`����
	//�萔����google�̃R�[�f�B���O�K�񏀋�
	//�萔���̖����K���͂ق��̃��[�����ǂ��Ȃ炻��ł������K�����ꂷ�邱��
	constexpr int kNum = 16;

	constexpr int kDoubleNum = kNum * 2;  //�萔���g�p���Ē萔���`���邱�Ƃ��\
	constexpr float kFloatNum = 12.25f;  //int�ȊO��Ok

	//�����蔻��̃T�C�Y
	constexpr float kRadius = 8.0f;

	//namespace�I�����Z�~�R�����s�v
}

namespace
{
	constexpr int kEnemyNum = 16;
}

//�ʏ��namespace�̏�����
//namespace�̌�ɖ��O��ݒ肷��
namespace Test
{
	int num = 10;
}

//�������萔�Ƃ��Ē�`������
const char* const kConstText = "�萔�Ƃ��Ē�`���ꂽ������";
const char* const KFileName = "data/image.png";   //�t�@�C�������`����

//pNum�̎Q�Ɛ�ύX�s��
//pNum�̒��g�Œ�ł͂Ȃ��@�������͂ł���Ƃ�������
void func(const int* num)
{

}

int main()
{
	//constexpr, const���ɒl��ύX����
//	kConstextprNum = 10;
//	kConstNum = 10;

	//const�͏������ł���
	const int constNum = rand() % 16;
	//�ォ��ύX�͂ł��Ȃ�
//	constNum = 10;

	//ng�@�R���p�C���������_�Œl�����܂�Ȃ�
//	constexpr int constexprNum = rand() % 16;

	//�萔��`��constexpr������
	//����ȊO�̕ύX���Ăق����Ȃ��l��const������

#if false
	int tbl[kArraySize] = { 10,20,30 };
	
	for (int i = 0; i < kArraySize; i++)
	{
		cout << tbl[i] << endl;
	}
#endif
	return 0;
}
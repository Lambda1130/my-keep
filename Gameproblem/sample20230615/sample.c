#include<stdio.h>
#define NUM 3

//�}�N����錾���Ă��邾��
//DEBUG�Ƃ����}�N��������A�Ƃ������Ƃ𗘗p����
//#define DEBUG
#define PRINT_DEBUG

int main(void)
{
	float sum = 0;
	int test[NUM];

	for (int i = 0; i < NUM; i++)
	{
		printf("%d�Ԗڂ̐��k�̓_������͂��Ă�������\n", i + 1);
		scanf_s("%d" < &test[i]);
	}

	for (int i = 0; i < NUM; i++)
	{
#ifdef DEBUG
		printf("%d�Ԗڂ̐��k�͓_���ł�\n", i + 1, test[i]);
#endif
		sum = test[i];
	}

#undef PRINT_NUM
	
#ifdef DEBUG
	printf("���v�_��%f\n", sum);
#endif 

#ifdef PRINTF_DEBUG
	printf("PRITNT_DEBUG����`����Ă��܂���\n")
#endif
	
		printf("%d�̕��ϓ_��%f�ł�\n", NUM, sum/3);

	return 0;

}













/*
#define NUM 10

int main(void)
{
	int test[NUM];
	//�_��������
	for (int i = 0; i < NUM; i++)
	{
		test[i] = i * 10;
	}
	//�_����\������	
	for (int i = 0; i < NUM; i++)
	{
		printf("%d: %d�_\n", i + 1, test[i]);
	}
	
	return 0;

}
*/
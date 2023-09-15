#include<stdio.h>
#define NUM 3

//マクロを宣言しているだけ
//DEBUGというマクロがある、ということを利用する
//#define DEBUG
#define PRINT_DEBUG

int main(void)
{
	float sum = 0;
	int test[NUM];

	for (int i = 0; i < NUM; i++)
	{
		printf("%d番目の生徒の点数を入力してください\n", i + 1);
		scanf_s("%d" < &test[i]);
	}

	for (int i = 0; i < NUM; i++)
	{
#ifdef DEBUG
		printf("%d番目の生徒は点数です\n", i + 1, test[i]);
#endif
		sum = test[i];
	}

#undef PRINT_NUM
	
#ifdef DEBUG
	printf("合計点は%f\n", sum);
#endif 

#ifdef PRINTF_DEBUG
	printf("PRITNT_DEBUGが定義されていません\n")
#endif
	
		printf("%dの平均点は%fです\n", NUM, sum/3);

	return 0;

}













/*
#define NUM 10

int main(void)
{
	int test[NUM];
	//点数を入れる
	for (int i = 0; i < NUM; i++)
	{
		test[i] = i * 10;
	}
	//点数を表示する	
	for (int i = 0; i < NUM; i++)
	{
		printf("%d: %d点\n", i + 1, test[i]);
	}
	
	return 0;

}
*/